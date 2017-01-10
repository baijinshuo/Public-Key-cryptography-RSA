#include<stdio.h>
#include<stdlib.h> 
int  prime(int in)
{
	int key=0,i,j;
	i=in/2;
	for(j=2;j<=i;j++)
	{
		if(in%j==0)
		{
			key=1;
			break;
		}
	}
	return key;
}

int test(int a1,int a2)
{
	int i;
	do
	{
		i=a2%a1;
		a2=a1;
		a1=i;
	}while(i!=0&&i!=1);
	return i;
}

int main()
{
	int p=0,q=0,k=0;
    int n,n0,e;
    int d=1,M=1,C=1,i,s=1,h,se=1;
	do{
	printf("Input prime number P:");
	scanf("%d",&p);
	k=prime(p);
	if(k==1)
	printf("p is not a prime number!\n");
	}while(k==1);
	do{
	printf("Input prime number q:");
	scanf("%d",&q);
	k=prime(q);
	if(k==1)
	printf("q is not a prime number!\n");
	}while(k==1);
	n=p*q;
	n0=(p-1)*(q-1);
	do{
	printf("Input a random number between 0 and %d(they are mutually prime numbers)",n0);
	scanf("%d",&e);
	k=test(e,n0);
	if(k==0)
	printf("Input number and %d and not mutually prime number!\n",n0);
	}while(k==0);
	do{
		d++;
		k=(d*e)%n0;
	}while(k!=1);
	printf("private key is %d£¬public key is %d and %d.",d,e,n);
	printf("Encryption and decryption£¨1£©Signature£¨2£©");
	scanf("%d",&k);
	if(k==1)
	{
	printf("Encryption£¨1£©Decryption£¨2£©");
	scanf("%d",&k);
	if(k==1)
	{
		printf("Please input plain text£º");
		scanf("%d",&M);
		for(i=1;i<=e;i++)
		C=(C*M)%n;
		printf("cipher text is£º%d",C);
	}
	else
	{
		printf("Please input cipher text£º");
		scanf("%d",&C);
		for(i=1;i<=d;i++)
		M=(C*M)%n;
		printf("plain text is£º%d",M);
	}
	}
	else 
	{
		printf("Please input the hash number of plain text£º");
		scanf("%d",&h);
		for(i=0;i<=d;i++)
		s=(s*h)%n;
		printf("The signature is %d",s);
		for(i=0;i<=e;i++)
		se=(se*s)%n;
		if(h%n==se)
		printf("Verification succeed!");
		else
		printf("Vefification failed!");
	}
	getchar();
	putchar(getchar());
	return 0;
}
