#include "cir_cordic.h"

void pre_cir_cordic (di_t full_alpha, di_t &alpha, flag_t &flag)
{
	if(full_alpha > PI/2)
	{
		alpha = PI - full_alpha;
		flag = 2;
	}
	else if(full_alpha < -PI/2)
	{
		alpha = -PI - full_alpha;
		flag = 3;
	}
	else
	{
		alpha = full_alpha;
		flag = 0;
	}

}

void cir_cordic_calculate(di_t alpha, flag_t flag, do_t &mysin, do_t &mycos, flag_t &flag_delay)
{
	const int N = 16;
	do_t xi[N];
	do_t yi[N];
	di_t zi[N];
	flag_t flag_delay_a[N];
	
	xi[0] = Kn;
	yi[0] = 0;
	zi[0] = alpha;
	flag_delay_a[0] = flag;

	const di_t myarctan[16] = {
		#include "myarctan.h"
	};
	int m = 0;
	loop:
	for(m = 0 ; m < N; m++)
	{
		if(zi[m] >= 0)
		{
			xi[m+1] = xi[m] - (yi[m] >> m);
			yi[m+1] = yi[m] + (xi[m] >> m);
			zi[m+1] = zi[m] - myarctan[m];
		}
		else
		{
			xi[m+1] = xi[m] + (yi[m] >> m);
			yi[m+1] = yi[m] - (xi[m] >> m);
			zi[m+1] = zi[m] + myarctan[m];
		}
		flag_delay_a[m+1]  = flag_delay_a[m];
	}
	mysin = yi[N-1];
	mycos = xi[N-1];
	flag_delay = flag_delay_a[N-1];
}

void post_cir_cordic (do_t mysin, do_t mycos, flag_t flag_delay, do_t &sin_out, do_t &cos_out)
{
	switch(int(flag_delay))
	{
		case 2: sin_out = mysin; cos_out = -mycos; break;
		case 3: sin_out = mysin; cos_out = -mycos; break;
		default : sin_out = mysin; cos_out = mycos; break;
	}
}

void cir_cordic(di_t full_alpha, do_t &sin_out, do_t &cos_out)
{
	di_t alpha;
	flag_t flag;
	do_t mysin;
	do_t mycos;
	flag_t flag_delay;

	pre_cir_cordic(full_alpha, alpha, flag);
	cir_cordic_calculate(alpha, flag, mysin, mycos, flag_delay);
	post_cir_cordic(mysin, mycos, flag_delay, sin_out, cos_out);
}
