#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define lr 0.01 
#define seuil 0.00001
#define maximum 10000

double predict(double x,double a,double b){
    return a*x+b;
}

int main(){
    srand(time(NULL));
    double x[N],y[N],y_pred[N],w;
    double a1,b1;
    printf("saisir a1:");
    scanf("%lf", &a1);
    printf("saisir b1:");
    scanf("%lf", &b1);
    for(int i=0;i<N;i++){
        w=(double)rand()/RAND_MAX;
        x[i]=(double)rand()/RAND_MAX;
        y[i]=(a1 * x[i]) + b1 + w;
    }

    double a = (double)rand()/RAND_MAX;
    double b = (double)rand()/RAND_MAX;
    
    double da,db;
    int j=0;
    while(j<maximum){
        da=0.0;
        db=0.0;
        for(int i=0;i<N;i++){
            y_pred[i]=predict(x[i],a,b);
            da += 2 * (y_pred[i] - y[i]) * x[i];
            db += 2 * (y_pred[i] - y[i]);
        }
        da/=N;
        db/=N;
        a -= lr * da;
        b -= lr * db;
        if(fabs(da) < seuil && fabs(db) < seuil){
            break;
        }
        j++;
    }
    printf("Valeurs predites:\na = %f | b = %f\n", a, b);
    printf("%d",j);
    return 0;
}