#include<iostream>
using namespace std;
typedef long long ll;
const ll MAX=1000000;
struct Matrix
{
    long long x[2][2]=
    {
        {1 , 1},
        {1 , 0}
    };
};
Matrix operator * (Matrix a,Matrix b)
{
    Matrix res;
    for ( int i=0;i<2;i++)
        for ( int j=0;j<2;j++)
    {
        res.x[i][j]=0;
        for ( int k=0;k<2;k++)
                res.x[i][j]=(res.x[i][j]+a.x[i][k]*b.x[k][j]) % MAX;
    }
    return res;

}
Matrix Pow(Matrix a, long long n)
{
if ( n==1 ) return a;
 Matrix tmp=Pow(a,n/2);
 if ( n % 2 ==0 ) return (tmp*tmp);
 return (tmp*tmp*a);
}
int main()
{
  ll n;
  cin>>n;

  Matrix a;
  a=Pow(a,n);
   //for ( int i=0;i<2;i++)
     //   {
       //     for ( int j=0;j<2;j++)
         //    cout<<a.x[i][j]<<" ";
           //  cout<<endl;
        //}
  cout<<a.x[0][1];
}

