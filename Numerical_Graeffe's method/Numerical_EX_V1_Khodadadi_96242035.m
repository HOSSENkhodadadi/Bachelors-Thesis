int main()
{
    int n=0;
    int iter=0;
    int i=0;
    int j=0;
    int m=0;
    int k=1;
    int keep;
     long double sum=0;
    int sign=-1;
     long  double ce[100];
     long double nce[100];
    cout<<"Enter number of iteration"<<endl;
    cin>>iter;
    keep=iter;
    cout<<"Enter polynomial degree"<<endl;
    cin>>n;
    cout<<"Enter Coefficients of polynomial"<<endl;
    i=n;
    while (i>=0)
    {
        cin>>ce[i];
        i=i-1;
    }
    i=n;

    while (iter>0)
    {
        while (j<=2*n)
        {

            sum += ce[j/2]*ce[j/2];
            while (k<=j/2 && j!=2*n)
            {
                sum +=sign *2*ce[j/2+k] * ce[j/2-k];
                sign =sign * (-1);
                k=k+1;
            }
            sign =-1;
            k=1;
            nce[m]=sum;
            sum=0;
            m++;
            j=j+2;
        }
        j=0;
        m=0;
        k=1;
        while (i>=0)
        {
            ce[i]=nce[i];
            i--;
        }
        i=n;
        iter=iter-1;
    }
    i=n;
    while (i>0)
    {
        //cout<<ce[i]<<endl;
        cout<<pow(abs(ce[i-1])/abs(ce[i]),1/pow(2,keep))<<endl;
        i=i-1;
    }


    return 0;
}