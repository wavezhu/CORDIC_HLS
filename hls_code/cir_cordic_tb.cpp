#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include "cir_cordic.h"
#include "ReadFileVec.h"

using namespace std;

int main()
{
    const int N = 629;
    char *fd_alpha = "myalpha.dat";
    char *fd_sin = "mysin.dat";
    char *fd_cos = "mycos.dat";

    di_t alpha[N] = {0};
    do_t sinRef[N] = {0};
    do_t cosRef[N] = {0};
    do_t sinres[N] = {0};
    do_t cosres[N]= {0};

    int ErrCntSin = 0;
    int ErrCntCos = 0;
    float precision = pow(2, -10);
    int i;

    ReadFileVec <N, di_t, float> (fd_alpha, alpha);
    ReadFileVec <N, do_t, float> (fd_sin, sinRef);
    ReadFileVec <N, do_t, float> (fd_cos, cosRef);

    for(i = 0; i < N; i++)
    {
        cir_cordic(alpha[i], sinres[i], cosres[i]);
    }

    cout << setfill('-') << setw(90) << '-' << '\n';
    cout << setfill(' ') << setw(18) << right << "Alpha";
    cout << setfill(' ') << setw(18) << right << "sin";
    cout << setfill(' ') << setw(18) << right << "sinRef";
    cout << setfill(' ') << setw(18) << right << "cos";
    cout << setfill(' ') << setw(18) << right << "cosRef" << '\n';
    cout << setfill('-') << setw(90) << '-' << '\n';

    for (i = 0; i < N; i++)
    {
        cout << setfill(' ') << setw(18) << right << alpha[i];
        cout << setfill(' ') << setw(18) << right << sinres[i];
        cout << setfill(' ') << setw(18) << right << sinRef[i];
        cout << setfill(' ') << setw(18) << right << cosres[i];
        cout << setfill(' ') << setw(18) << right << cosRef[i];

        if(abs(float(sinres[i] - sinRef[i])) > precision)
        {
            ErrCntSin++;
            cout << setfill(' ') << setw(18) << right << "(sin failed)";
        }

        if(abs(float(cosres[i] - cosRef[i])) > precision)
        {
            ErrCntCos++;
            cout << setfill(' ') << setw(18) << right << "(cos failed)";
        }
        cout << '\n';
    }

    cout << setfill('-') << setw(90) << '-' << '\n';
    
    if(ErrCntSin + ErrCntCos >0)
    {
        if(ErrCntSin > 0)
        {
            cout << "There are " << ErrCntSin << "sin results failed" << '\n';
        }
        
        if(ErrCntCos > 0)
        {
            cout << "There are " << ErrCntCos << "sin results failed" << '\n';
        }
        cout << "Test failed for precision: " << precision << '\n';
        cout << setfill('-') << setw(90) << '-' <<'\n';
        return 1;
    }
    else
    {
        
        cout << "Test Passed for precision: " << precision << '\n';
        cout << setfill('-') << setw(90) << '-' <<'\n';
        return 0;
    }

}
