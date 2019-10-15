#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int p,q,flag,N,mul,choice,f;
int e,d;
char msg[200],enc[200],dec[200];

int isprime(int prm);
int gcd(int n1,int n2);
int cale();
int cald();
void encrypt();
void decrypt();

void main()
{

    printf("Enter the first prime number:");
    scanf("%d",&p);
    flag=isprime(p);
    if(flag==0)
        printf("Wrong input.\n");

    printf("Enter the second prime number:");
    scanf("%d",&q);
    flag=isprime(q);
    if(flag==0)
        printf("Wrong input.\n");


    scanf("%d\n%d",&e,&d);
    printf("\nEnter your message in small letters:");
    scanf("%s",msg);

    N=p*q;
    mul=(p-1)*(q-1);

    cald();

    printf("To encrypt press 1\nTo decrypt press 2\n");
    scanf("%d",&choice);
    switch(choice)
    {
         case 1:
             encrypt();
             break;
         case 2:
             decrypt();
             break;

    }
    printf("%d\n%d",cale(),cald());


}

int isprime(int prm)
{
    int i;
    for(i=2;i<=prm/2;i++)
    {
        if(prm%i==0)
            return 0;
    }

     return 1;
}

int gcd(int n1,int n2)
{
    int i,gcd;
    for(i=1; i <= n1 && i <= n2; ++i)
    {
        // Checks factor for both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
    return gcd;
}

int cale()
{
    int i,a;

    for(e=2;e<mul;e++)
    {
        if(gcd(e,mul)==1)
        break;

    }
    return e;
}

int cald()
{
    int i;
    for(d=1;d<mul;d++)
    {
        i=(d*cale())%mul;
        //printf("%d\t%d\n",d,i);
        if(i==1)
            break;
    }
    return d;
}

void encrypt()
{
    int i,len,a,b;
    int en;
    char c;
    len=strlen(msg);
    for(i=0;i<len;i++)
    {
        c=msg[i];
        a=c-96;
        en=pow(a,cale());
        b=en%N;
        enc[i]=b+96;
    }
   printf("\nYour encrypted message is:\n");
   printf("%s",enc);
}

void decrypt()
{
    int i,de,len,a,b;
    char c;
    len=strlen(msg);
    for(i=0;i<len;i++)
    {
        c=msg[i];
        a=c-96;
        de=pow(a,cald());
        b=de%N;
        dec[i]=b+96;
    }
   printf("\nYour encrypted message is:\n");
    printf("%s",dec);

}

