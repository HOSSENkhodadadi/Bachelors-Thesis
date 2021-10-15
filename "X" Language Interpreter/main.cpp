//agar , akhar bashad
//mofasser zaban x
//bebin mitoni as vector estefadeh koni?
//bayad hame maghader k neghah darad
//tedad anasori ke har dastoor mi girad add
//tabe cstr baraye tabdil reshte be adad
//tavabe str//
//samt chap va rast ro baraye adress neghah dashtam
//sort1
#include <iostream>
#include<fstream>
#include<cstdlib>
#include <conio.h>
//#include<vector>
#include<string>
#include <nodet.h>
#include<ctype.h>
#include<stdio.h>
#include<sstream>
using namespace std;
bool sign=true;
int counter=0;//?????? ????? ???? ?????
struct cmdamalgar //????? ????? ???? ??????? ????? ? ?????
{

    string command;
    string amalgar;
};
struct zakhire
{
    string names;//asami motaghaier ha ra zakhire mi konad
    long INTI;
    float REALF;
    bool ior;
}   zarray[200];
int command_check(string command,string amalgar);
int main();
//tabe check motaghayer reshte ra gherefte va agar adad bood be sourat ashari barmigardanad agar mathaghyer bood andis zakhire sazi ra mi dehad,dar gheyr in sorat error
// ret=0->khataie syntax motaghayer
//ret=1->andis mothayer dade shode ra bar mi gardanad
//ret=2->adad vared shode ra be sorat float be khruji mi dehad
//ret=3->mothayer peydanashod
int  check (string name, float &export1,int &andis )
{
    int ret,t;
    int t1=0,t2=0,flag=0;


    for(int i=0; i<name.length(); i++)
    {
        if (((int)name[i]<=57)&&(48<=(int)name[i])||(int) name[i]==46||(int)name[0]==45)

            t1++;
        if(((int)name[i]<=90)&&(65<=(int)name[i]))
            t2++;
    }
    if(t1==name.length())
    {
        ret=2;
        istringstream(name)>>export1;
        return ret;
    }
    else if(t2==name.length())
    {

        for(int i=0; i<=counter; i++ )
        {
            if(name==zarray[i].names)
            {
                t=i;
            }
        }
        if(t<=counter&&t>=0)
        {
            andis=t;
            ret=1;
            return ret;
        }
        if(!(t<=counter&&t>=0))
        {
            ret=3;
            return ret;
        }
    }
    if (name.length()>8)//8888888888
    {
        ret=0;
        return ret;
    }
    else

    {
        ret=0;
    }
    return ret;
}
string space_akhar(string s)//????? ???? ??? ????? ??? ??? ?? ??
{
    int shomarande_space=0,tool=s.length()-1;
    if(s[s.length()-1] == ' ')
    {
        while(s[tool]==' ')
        {


            if(s[tool]==' ')

                shomarande_space++;
            tool--;
        }

        s.erase(tool+1,shomarande_space);
        return s;
    }
    else
    {
        return s;
    }
}
string space_aval(string s)//????? ???? ??? ??????? ????? ?? ??? ?? ??
{
    if(s[0]==' ')
    {
        int shomarande_space=0;
        while(s[shomarande_space]==' ')
            shomarande_space++;
        s.erase(0,shomarande_space);
        return s;
    }
    else
        return s;
}
cmdamalgar dotikekonande (string s)//????? ???? ??? ???? ??? ???? ????? ? ??? ????? ??
{
    int x=0;
    while(s[x] != ' ' && x!=s.length())
        x++;
    cmdamalgar h;
    int seperator=0;
    if(x != s.length())
    {
        s=space_akhar(s);
        s=space_aval(s);
        cmdamalgar h;
        int seperator=0;
        while(s[seperator] != ' ')
            seperator++;
        string cmd;
        cmd=s;
        int tool=s.length();
        cmd.erase(seperator,tool-seperator);
        string amlgr;
        amlgr=s;
        amlgr.erase(0,seperator);
        int c,f=0,shomarande=0;
        amlgr=space_aval(amlgr);
        while(shomarande<amlgr.length())
        {
            if(amlgr[shomarande]==',')
                f++;
            shomarande++;
        }
        shomarande++;
        h.amalgar=amlgr;
        h.command=cmd;
        return h;
    }
    else
    {
        if(s == "END"||s =="end"||s =="End"||s =="ENd"||s =="eND"||s=="enD")
        {
            h.command="END";
            h.amalgar=" ";//???????????????????????????????????
        }
        else
        {
            h.command="0";
            h.amalgar="0";
        }
        return h;
    }
}
//#include<iostream>
//using namespace std;
void sort1(string amalgar)
{
    string name="";
    float ar[100];
    int j, ret=10,andis,i=0,x=0;
    float export1;
    for( i=0; i<amalgar.length(); i++)
    {
        for (j=i; amalgar[j]!=','&&(j<amalgar.length()); j++)
        {
            name+=amalgar[j];
        }
        i=j;
        name=space_aval(name);//hazf fasele az aval , akhar khat
        name=space_akhar(name);
        ret=check (name,export1,andis);
        if(ret==0||ret==1||ret==3)
        {
            cout<<"motaghaier  "<<name<<" adad nist"<<endl;
            sign=false;
        }


        else if (ret==2)
        {

            ar[x]=export1;
            x++;

        }
        name="";
    }
    for(int k=0; k<x; k++)
    {
        for(int m=k+1; m<x; m++)
        {
            if(ar[m]<ar[k])
                swap(ar[m],ar[k]);
        }
    }
    for(int k=0; k<x; k++)
        cout<<ar[k]<<"\t";
}
//motaghayer-haie-sahih va maghader an ha ra zakhire va ghabel dastresi me konad
void funcint(string amalgar)
{
    string name="";
    int j, ret=10,andis;
    float export1;
    for(int i=0; i<amalgar.length(); i++)
    {
        for (j=i; amalgar[j]!=','&&(j<amalgar.length()); j++)
        {
            name+=amalgar[j];
        }
        i=j;
        name=space_aval(name);//hazf fasele az aval , akhar khat
        name=space_akhar(name);
        ret=check (name,export1,andis);
        // cout<<name<<endl;
        // cout<<ret;
        if(ret==0||ret==2)
        {
            cout<<"motaghaier  "<<name<<" sahih nist"<<endl;
            sign=false;
        }

        else if(ret==1)
        {
            cout <<"motaghaier "<<name<<"  ghablan tarif shode"<<endl;
            sign=false;

        }
        else if (ret==3)
        {
            zarray[counter].names=name;
            zarray[counter].ior=true;//be neshane in ke real nist
            counter++;

        }
        name="";
    }
}
//motaghayer-haie-haghighi va maghader an ha ra zakhire va ghabel dastresi me konad
void funcreal(string amalgar)
{
    string name="";
    int j, ret=10,andis;
    float export1;
    for(int i=0; i<amalgar.length(); i++)
    {
        for (j=i; amalgar[j]!=','&&(j<amalgar.length()); j++)
        {
            name+=amalgar[j];
        }
        i=j;
        name=space_aval(name);//hazf fasele az aval , akhar khat
        name=space_akhar(name);
        ret=check (name,export1,andis);
        // cout<<name<<endl;
        // cout<<ret;
        if(ret==0||ret==2)

        {
            cout<<"motaghaier "<<name<<" sahih nist"<<endl;
            sign=false;
        }
        else if(ret==1)
        {
            cout <<"motaghaier "<<name<<" ghablan tarif shode"<<endl;
            sign=false;
        }

        else if (ret==3)
        {
            zarray[counter].names=name;
            zarray[counter].ior=false;//be neshane in int nist
            counter++;
        }
        name="";
    }
}
// in tabe braie meghdar dehi estefade mi shavad
void funcassign (string amalgar)
{
    string name ;
    string number;
    int i=0,flag=0,ret1=10,ret2=10,andis1,andis2;
    float export1,export2;
    for ( i=0; amalgar[i]!=','; i++)
    {
        name+=amalgar[i];
    }
    name=space_aval(name);//hazf fasele az aval , akhar khat
    name=space_akhar(name);
    ret1=check (name,export1,andis1);
    if(ret1==0||ret1==2)
    {
        cout<<"motaghaier  "<<name<<" sahih nist"<<endl;
        sign =false;

    }
    else if (ret1==3)
    {
        cout<<"motaghaier  "<<name<<" peida nashod"<<endl;
        sign =false;

    }
    else if(ret1==1)
    {
        i++;
        for ( i; i<amalgar.size(); i++)
            number+=amalgar[i];

        number=space_aval(number);//hazf fasele az aval , akhar khat
        number=space_akhar(number);
        ret2=check (number,export2,andis2);
        if(ret2==1)
        {
            if (zarray[andis1].ior==true)
            {
                if(zarray[andis2].ior==true)
                    zarray[andis1].INTI=zarray[andis2].INTI;
                else if(zarray[andis2].ior==false)
                    zarray[andis1].INTI=zarray[andis2].REALF;
            }
            else if(zarray[andis1].ior==false)
            {
                if(zarray[andis2].ior==true)
                    zarray[andis1].REALF=zarray[andis2].INTI;
                else if(zarray[andis2].ior==false)
                    zarray[andis1].REALF=zarray[andis2].REALF;
            }
        }
        else if(ret2==2)
        {
            if (zarray[andis1].ior==true)
                zarray[andis1].INTI=export2;
            else if(zarray[andis1].ior==false)
                zarray[andis1].REALF=export2;
        }
        else if(ret2==0)
        {
            sign=false;
            cout<<"motaghaier  "<<number<<" sahih nist"<<endl;
        }

        else if(ret2==3)
        {
            sign =false;
            cout<<"motaghaier  "<<number<<" peida nashod"<<endl;
        }

    }
}
//tabe print
void funcprint (string amalgar)
{
    int ret=10,andis;
    float export1;
    amalgar=space_aval(amalgar);//hazf fasele az aval , akhar khat
    amalgar=space_akhar(amalgar);
    ret=check(amalgar,export1,andis);
    if(ret==3)
    {
        sign =false;
        cout<<"motaghaier  "<<amalgar<<" peida nashod"<<endl;
    }
    else if (ret==2)
    {
        sign=false;
        cout<<"motaghaier  "<<amalgar<<" sahih nist"<<endl;
    }
    else if(ret==1)
    {
        if(zarray[andis].ior==true)
            cout<<zarray[andis].INTI<<endl;
        else if(zarray[andis].ior==false)
            cout<<zarray[andis].REALF<<endl;
    }
    else if(ret==0)
    {
        if(amalgar[amalgar.length()-1]=='"'&&amalgar[0]=='"')
        {
            for(int i=1; i<amalgar.length()-1; i++)
                cout<<amalgar[i];
        }
        else
        {
            cout<<"motaghaier  "<<amalgar<<" sahih nist"<<endl;
            sign =false;
        }

    }
}
void funcread (string amalgar)
{
    int ret=10,andis;
    string amalgar2;
    float meghdar;
    float export1;
    cin>>meghdar;
    ret=check(amalgar,export1,andis);
    if (ret==0||ret==2)
    {
        cout<<"motaghaier  "<<amalgar<<" sahih nist"<<endl;
        sign=false;
    }

    else if(ret==3)
    {
        cout<<"motaghaier  "<<amalgar<<" peidanashod"<<endl;
        sign=false;
    }

    else if(ret==1)
    {
        getline(cin,amalgar2);
        istringstream(amalgar2)>>meghdar;
        if(zarray[andis].ior==true)
            zarray[andis].INTI=meghdar;
        else if(zarray[andis].ior==false)
            zarray[andis].REALF=meghdar;
    }
}
void  funcdivi(string s)
{
    string tool[3];
    int ret;
    s=space_aval(s);
    s=space_akhar(s);
    int b=0,a=0;
    while(a<s.length())
    {
        if(s[a]==',')
            b++;
        a++;
    }
    if(b==2)
    {
        int j=0;
        int i=0;
        while(j<s.length())
        {
            tool[i]=space_akhar(tool[i]);
            tool[i]=space_aval(tool[i]);
            if(s[j]==',')
            {
                i++;
            }
            else
            {
                tool[i]+=s[j];
            }
            j++;
        }
        int ret;
        float export1;
        int andis1;
        ret=check(tool[0],export1,andis1);
        if(ret==1)
        {
            float export2;
            int andis2;
            ret=check(tool[1],export2,andis2);
            if(ret==3 || ret == 0)
            {
                cout<<"voroodi eshtebah";
                sign=false;
            }
            else if(ret==1)
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis2].ior != 1 || zarray[andis3].ior !=1 )
                    {
                        cout<<"faghat adade sahih";
                        sign=false;
                        return;
                    }
                    else
                    {
                        int u;
                        u=zarray[andis2].INTI/zarray[andis3].INTI;
                        if(zarray[andis1].ior==1)
                        {
                            zarray[andis1].INTI=u;
                        }
                        if(zarray[andis1].ior==0)
                        {
                            zarray[andis1].REALF=u;
                        }
                    }
                }
                else
                {
                    if(zarray[andis2].ior != 1 || int(export3)!= export3)
                    {
                        cout<<"faghat adade sahih";
                        sign=false;
                        return;
                    }
                    else
                    {
                        int u;
                        u=zarray[andis2].INTI/export3;
                        if(zarray[andis1].ior==1)
                        {
                            zarray[andis1].INTI=u;
                        }
                        if(zarray[andis1].ior==0)
                        {
                            zarray[andis1].REALF=u;
                        }
                    }
                }
            }
            else
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis3].ior == 0 || int(export2)!=export2)
                    {
                        cout<<"adade sahih vared konid";
                        sign=false;
                    }
                    else
                    {
                        int u;
                        u=export2/zarray[andis3].INTI;
                        if(zarray[andis1].ior==1)
                        {
                            zarray[andis1].INTI=u;
                        }
                        if(zarray[andis1].ior==0)
                        {
                            zarray[andis1].REALF=u;
                        }
                    }
                }
                else
                {
                    float u;
                    if(int(export2)!=export2 || int(export2)!=export2)
                    {
                        cout<<"adad e sahih vared konid";
                        sign=false;
                        return;
                    }
                    export2=export2/export3;
                    u=export2;

                    if(zarray[andis1].ior==1)
                    {
                        zarray[andis1].INTI=u;
                    }
                    if(zarray[andis1].ior==0)
                    {
                        zarray[andis1].REALF=u;
                    }
                }
            }
        }
        else
        {
            cout<<"ebteda moteghaier voroodi ra vared konid";
            sign=false;
            return;
        }
    }
    else
    {
        cout<<"dastoore divi 3 voroodi darad";
        sign=false;
        return;
    }
}
void  funcdivr(string s)
{
    string tool[3];
    int ret;
    s=space_aval(s);
    s=space_akhar(s);
    int b=0,a=0;
    while(a<s.length())
    {
        if(s[a]==',')
            b++;
        a++;
    }

    if(b==2)
    {

        int j=0;
        int i=0;
        while(j<s.length())
        {
            tool[i]=space_akhar(tool[i]);
            tool[i]=space_aval(tool[i]);
            if(s[j]==',')
            {

                i++;
            }
            else
            {
                tool[i]+=s[j];

            }
            j++;
        }
        int ret;
        float export1;
        int andis1;
        ret=check(tool[0],export1,andis1);


        if(ret==1)
        {

            if(zarray[andis1].ior==0)
            {
                float export2;
                int andis2;
                ret=check(tool[1],export2,andis2);
                if(ret==3 || ret == 0)
                {
                    cout<<"voroodi vojood nadarad";
                }
                else if(ret==1)
                {
                    float export3;
                    int andis3;
                    ret=check(tool[2],export3,andis3);
                    if(ret == 3 || ret == 0)
                    {
                        cout<<"voroodi vojood nadarad";
                    }
                    else if(ret==1)
                    {


                        float u1;
                        float u2;
                        float u3;
                        if(zarray[andis2].ior == 1 && zarray[andis3].ior == 1)
                        {
                            u1=zarray[andis2].INTI;
                            u2=zarray[andis3].INTI;
                            u3=u1/u2;
                            zarray[andis1].REALF=u3;
                        }
                        else if(zarray[andis2].ior == 0 && zarray[andis3].ior == 1)
                        {
                            u1=zarray[andis2].REALF;
                            u2=zarray[andis3].INTI;
                            u3=u1/u2;
                            zarray[andis1].REALF=u3;
                        }
                        else if(zarray[andis2].ior == 0 && zarray[andis3].ior == 0)
                        {
                            u1=zarray[andis2].REALF;
                            u2=zarray[andis3].REALF;
                            u3=u1/u2;
                            zarray[andis1].REALF=u3;
                        }
                        else if(zarray[andis2].ior == 1 && zarray[andis3].ior == 0)
                        {
                            u2=zarray[andis3].REALF;
                            u1=zarray[andis2].INTI;
                            u3=u1/u2;
                            zarray[andis1].REALF=u3;
                        }
                    }
                    else
                    {


                        if(zarray[andis2].ior ==1)
                        {
                            zarray[andis1].REALF=float(zarray[andis2].INTI)/float(export3);
                        }
                        else
                        {
                            zarray[andis1].REALF=float(zarray[andis2].REALF)/float(export3);
                        }
                    }
                }

                else
                {


                    float export3;
                    int andis3;
                    ret=check(tool[2],export3,andis3);
                    if(ret == 3 || ret == 0)
                    {
                        cout<<"voroodi eshtebah";
                    }
                    else if(ret==1)
                    {

                        if(zarray[andis3].ior==1)
                            zarray[andis1].REALF=float(export2)/float(zarray[andis3].INTI);
                        else
                        {
                            zarray[andis1].REALF=float(export2)/float(zarray[andis3].REALF);
                        }
                    }

                    else
                    {

                        zarray[andis1].REALF=float(export2)/float(export3);

                    }

                }
            }
            else
            {
                cout<<"adad va moteghayer haye sahih  vared nakonid";
            }
        }


        else
        {
            cout<<"ebteda moteghaier voroodi ra vared konid";
            return;
        }
    }
    else
    {
        cout<<"dastoore divi 3 voroodi darad";
        return;
    }
}
void  funcadd(string s)
{
    string tool[3];
    int ret;
    s=space_aval(s);
    s=space_akhar(s);
    int b=0,a=0;
    while(a<s.length())
    {
        if(s[a]==',')
            b++;
        a++;
    }
    if(b==2)
    {
        int j=0;
        int i=0;
        while(j<s.length())
        {
            tool[i]=space_akhar(tool[i]);
            tool[i]=space_aval(tool[i]);
            if(s[j]==',')
            {
                i++;
            }
            else
            {
                tool[i]+=s[j];
            }
            j++;
        }
        int ret;
        float export1;
        int andis1;
        ret=check(tool[0],export1,andis1);
        if(ret==1)
        {
            float export2;
            int andis2;
            ret=check(tool[1],export2,andis2);
            if(ret==3 || ret == 0)
            {
                cout<<"voroodi eshtebah";
                sign=false;
            }
            else if(ret==1)
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis1].ior==1)
                    {
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==1)
                            zarray[andis1].INTI=zarray[andis2].INTI + zarray[andis3].INTI;
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis2].INTI + zarray[andis3].REALF);
                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis2].REALF + zarray[andis3].REALF);

                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis3].INTI + zarray[andis2].REALF);

                    }
                    else{
                                                if(zarray[andis2].ior==1 && zarray[andis3].ior==1)
                            zarray[andis1].REALF=zarray[andis2].INTI + zarray[andis3].INTI;
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis2].INTI + zarray[andis3].REALF);
                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis2].REALF + zarray[andis3].REALF);

                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis3].INTI + zarray[andis2].REALF);

                    }
                }
                else
                {
                    if(zarray[andis1].ior==1){
                            if(zarray[andis2].ior==1){zarray[andis1].INTI=zarray[andis2].INTI+export3;}
                            if(zarray[andis2].ior==0){zarray[andis1].INTI=zarray[andis2].INTI+export3;}

                    }

                    if(zarray[andis1].ior==0){
                            if(zarray[andis2].ior==1){zarray[andis1].REALF=zarray[andis2].INTI+ float(export3);}
                            if(zarray[andis2].ior==0){zarray[andis1].REALF=zarray[andis2].REALF+float(export3);}

                            }
                }
            }
            else
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis1].ior==1){
                            if(zarray[andis3].ior==1){zarray[andis1].INTI=zarray[andis3].INTI+export2;}
                            if(zarray[andis3].ior==0){zarray[andis1].INTI=zarray[andis3].INTI+export2;}

                    }

                    if(zarray[andis1].ior==0){
                            if(zarray[andis3].ior==1){zarray[andis1].REALF=zarray[andis3].INTI+export2;}
                            if(zarray[andis3].ior==0){zarray[andis1].REALF=zarray[andis3].REALF+float(export2);}

                            }
                }
                else
                {
                if(zarray[andis1].ior==1){zarray[andis1].INTI=export2+export3;}
                if(zarray[andis1].ior==0){zarray[andis1].REALF=export2+export3;}
                }
            }
        }
        else
        {
            cout<<"ebteda moteghaier voroodi ra vared konid";
            sign=false;
            return;
        }
    }
    else
    {
        cout<<"dastoore DIVR 3 voroodi darad";
        sign=false;
        return;
    }
}
void  funcmult(string s)
{
    string tool[3];
    int ret;
    s=space_aval(s);
    s=space_akhar(s);
    int b=0,a=0;
    while(a<s.length())
    {
        if(s[a]==',')
            b++;
        a++;
    }
    if(b==2)
    {
        int j=0;
        int i=0;
        while(j<s.length())
        {
            tool[i]=space_akhar(tool[i]);
            tool[i]=space_aval(tool[i]);
            if(s[j]==',')
            {
                i++;
            }
            else
            {
                tool[i]+=s[j];
            }
            j++;
        }
        int ret;
        float export1;
        int andis1;
        ret=check(tool[0],export1,andis1);
        if(ret==1)
        {
            float export2;
            int andis2;
            ret=check(tool[1],export2,andis2);
            if(ret==3 || ret == 0)
            {
                cout<<"voroodi eshtebah";
                sign=false;
            }
            else if(ret==1)
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis1].ior==1)
                    {
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==1)
                            zarray[andis1].INTI=zarray[andis2].INTI * zarray[andis3].INTI;
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis2].INTI * zarray[andis3].REALF);
                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis2].REALF * zarray[andis3].REALF);

                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis3].INTI * zarray[andis2].REALF);

                    }
                    else{
                                                if(zarray[andis2].ior==1 && zarray[andis3].ior==1)
                            zarray[andis1].REALF=zarray[andis2].INTI * zarray[andis3].INTI;
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis2].INTI * zarray[andis3].REALF);
                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis2].REALF * zarray[andis3].REALF);

                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis3].INTI * zarray[andis2].REALF);

                    }
                }
                else
                {
                    if(zarray[andis1].ior==1){
                            if(zarray[andis2].ior==1){zarray[andis1].INTI=zarray[andis2].INTI*export3;}
                            if(zarray[andis2].ior==0){zarray[andis1].INTI=zarray[andis2].INTI*export3;}

                    }

                    if(zarray[andis1].ior==0){
                            if(zarray[andis2].ior==1){zarray[andis1].REALF=zarray[andis2].INTI*float(export3);}
                            if(zarray[andis2].ior==0){zarray[andis1].REALF=zarray[andis2].REALF*float(export3);}

                            }
                }
            }
            else
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis1].ior==1){
                            if(zarray[andis3].ior==1){zarray[andis1].INTI=zarray[andis3].INTI*export2;}
                            if(zarray[andis3].ior==0){zarray[andis1].INTI=zarray[andis3].INTI*export2;}

                    }

                    if(zarray[andis1].ior==0){
                            if(zarray[andis3].ior==1){zarray[andis1].REALF=zarray[andis3].INTI*export2;}
                            if(zarray[andis3].ior==0){zarray[andis1].REALF=zarray[andis3].REALF*float(export2);}

                            }
                }
                else
                {
                if(zarray[andis1].ior==1){zarray[andis1].INTI=export2*export3;}
                if(zarray[andis1].ior==0){zarray[andis1].REALF=export2*export3;}
                }
            }
        }
        else
        {
            cout<<"ebteda moteghaier voroodi ra vared konid";
            sign=false;
            return;
        }
    }
    else
    {
        cout<<"dastoore MULT 3 voroodi darad";
        sign=false;
        return;
    }
}
void  funcsub(string s)
{
    string tool[3];
    int ret;
    s=space_aval(s);
    s=space_akhar(s);
    int b=0,a=0;
    while(a<s.length())
    {
        if(s[a]==',')
            b++;
        a++;
    }
    if(b==2)
    {
        int j=0;
        int i=0;
        while(j<s.length())
        {
            tool[i]=space_akhar(tool[i]);
            tool[i]=space_aval(tool[i]);
            if(s[j]==',')
            {
                i++;
            }
            else
            {
                tool[i]+=s[j];
            }
            j++;
        }
        int ret;
        float export1;
        int andis1;
        ret=check(tool[0],export1,andis1);
        if(ret==1)
        {
            float export2;
            int andis2;
            ret=check(tool[1],export2,andis2);
            if(ret==3 || ret == 0)
            {
                cout<<"voroodi eshtebah";
                sign=false;
            }
            else if(ret==1)
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis1].ior==1)
                    {
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==1)
                            zarray[andis1].INTI=zarray[andis2].INTI - zarray[andis3].INTI;
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis2].INTI - zarray[andis3].REALF);
                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis2].REALF - zarray[andis3].REALF);

                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].INTI=int(zarray[andis3].INTI - zarray[andis2].REALF);

                    }
                    else{
                                                if(zarray[andis2].ior==1 && zarray[andis3].ior==1)
                            zarray[andis1].REALF=zarray[andis2].INTI - zarray[andis3].INTI;
                        if(zarray[andis2].ior==1 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis2].INTI - zarray[andis3].REALF);
                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis2].REALF - zarray[andis3].REALF);

                        if(zarray[andis2].ior==0 && zarray[andis3].ior==0)
                            zarray[andis1].REALF=int(zarray[andis3].INTI -zarray[andis2].REALF);

                    }
                }
                else
                {
                    if(zarray[andis1].ior==1){
                            if(zarray[andis2].ior==1){zarray[andis1].INTI=zarray[andis2].INTI-export3;}
                            if(zarray[andis2].ior==0){zarray[andis1].INTI=zarray[andis2].INTI-export3;}

                    }

                    if(zarray[andis1].ior==0){
                            if(zarray[andis2].ior==1){zarray[andis1].REALF=zarray[andis2].INTI-float(export3);}
                            if(zarray[andis2].ior==0){zarray[andis1].REALF=zarray[andis2].REALF-float(export3);}

                            }
                }
            }
            else
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis1].ior==1){
                            if(zarray[andis3].ior==1){zarray[andis1].INTI=zarray[andis3].INTI-export2;}
                            if(zarray[andis3].ior==0){zarray[andis1].INTI=zarray[andis3].INTI-export2;}

                    }

                    if(zarray[andis1].ior==0){
                            if(zarray[andis3].ior==1){zarray[andis1].REALF=zarray[andis3].INTI-export2;}
                            if(zarray[andis3].ior==0){zarray[andis1].REALF=zarray[andis3].REALF-float(export2);}

                            }
                }
                else
                {
                if(zarray[andis1].ior==1){zarray[andis1].INTI=export2-export3;}
                if(zarray[andis1].ior==0){zarray[andis1].REALF=export2-export3;}
                }
            }
        }
        else
        {
            cout<<"ebteda moteghaier voroodi ra vared konid";
            sign=false;
            return;
        }
    }
    else
    {
        cout<<"dastoore SUB 3 voroodi darad";
        sign=false;
        return;
    }
}
void  funcmod(string s)
{
    string tool[3];
    int ret;
    s=space_aval(s);
    s=space_akhar(s);
    int b=0,a=0;
    while(a<s.length())
    {
        if(s[a]==',')
            b++;
        a++;
    }
    if(b==2)
    {
        int j=0;
        int i=0;
        while(j<s.length())
        {
            tool[i]=space_akhar(tool[i]);
            tool[i]=space_aval(tool[i]);
            if(s[j]==',')
            {
                i++;
            }
            else
            {
                tool[i]+=s[j];
            }
            j++;
        }
        int ret;
        float export1;
        int andis1;
        ret=check(tool[0],export1,andis1);
        if(ret==1)
        {
            float export2;
            int andis2;
            ret=check(tool[1],export2,andis2);
            if(ret==3 || ret == 0)
            {
                cout<<"voroodi eshtebah";
                sign=false;
            }
            else if(ret==1)
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis2].ior != 1 || zarray[andis3].ior !=1 )
                    {
                        cout<<"faghat adade sahih";
                        sign=false;
                        return;
                    }
                    else
                    {
                        int u;
                        u=zarray[andis2].INTI%zarray[andis3].INTI;
                        if(zarray[andis1].ior==1)
                        {
                            zarray[andis1].INTI=u;
                        }
                        if(zarray[andis1].ior==0)
                        {
                            zarray[andis1].REALF=u;
                        }
                    }
                }
                else
                {
                    if(zarray[andis2].ior != 1 || int(export3)!= export3)
                    {
                        cout<<"faghat adade sahih";
                        sign=false;
                        return;
                    }
                    else
                    {
                        int u;
                        u=zarray[andis2].INTI % int(export3);
                        if(zarray[andis1].ior==1)
                        {
                            zarray[andis1].INTI=u;
                        }
                        if(zarray[andis1].ior==0)
                        {
                            zarray[andis1].REALF=u;
                        }
                    }
                }
            }
            else
            {
                float export3;
                int andis3;
                ret=check(tool[2],export3,andis3);
                if(ret == 3 || ret == 0)
                {
                    cout<<"voroodi eshtebah";
                    sign=false;
                }
                else if(ret==1)
                {
                    if(zarray[andis3].ior == 0 || int(export2)!=export2)
                    {
                        cout<<"adade sahih vared konid";
                        sign=false;
                    }
                    else
                    {
                        int u;
                        u=int(export2)%zarray[andis3].INTI;
                        if(zarray[andis1].ior==1)
                        {
                            zarray[andis1].INTI=u;
                        }
                        if(zarray[andis1].ior==0)
                        {
                            zarray[andis1].REALF=u;
                        }
                    }
                }
                else
                {
                    float u;
                    if(int(export2)!=export2 || int(export2)!=export2)
                    {
                        cout<<"adad e sahih vared konid";
                        sign=false;
                        return;
                    }
                    u=int(export2)%int(export3);


                    if(zarray[andis1].ior==1)
                    {
                        zarray[andis1].INTI=u;
                    }
                    if(zarray[andis1].ior==0)
                    {
                        zarray[andis1].REALF=u;
                    }
                }
            }
        }
        else
        {
            cout<<"ebteda moteghaier voroodi ra vared konid";
            sign=false;
            return;
        }
    }
    else
    {
        cout<<"dastoore divi 3 voroodi darad";
        sign=false;
        return;
    }
}
void  funcrunf(string amalgarrunf)
{
    ifstream file1;
    int payan=-1;
    string command,amalgar;
    string voroodi;
    file1.open(amalgarrunf.c_str(),ios::in);
    if(!(file1.is_open()))
    {
        cout << "The file at location " << amalgarrunf << " failed to open" << endl;
        return;
    }
    else
    {
        while((!(file1.eof()))&&payan!=0&&sign!=false)//||flag!=-/)///flag error  ,end  moshkel tabe dotikekonande
        {

            cmdamalgar asli;
            cout<<"->"<<endl;
            getline(file1,voroodi);
            cout<<voroodi<<endl;
            voroodi=space_aval(voroodi);//hazf fasele az aval , akhar khat
            asli=dotikekonande(voroodi);
            amalgar=asli.amalgar;
            command=asli.command;
            command=space_akhar(command);
            amalgar=space_aval(amalgar);
            payan= command_check (command,amalgar);
        }
    }

    file1.close();

}
int command_check(string command,string amalgar)
{
    string rightstr[2000],leftstr[2000];
    int payan=1,i=0;
    for( i=0; i<command.size(); i++)
    {
        command[i]=chartoupper(command[i]);
    }
    if (command!="PRINT")
    {
        for( i=0; i<amalgar.size(); i++)
        {
            amalgar[i]=chartoupper(amalgar[i]);
        }
    }
    if(command == "INT")
    {
        funcint(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "REAL")
    {
        funcreal(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "SORT1")
    {
        sort1(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "ASSIGN")
    {
        funcassign(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "READ")
    {
        cout<<"?";
        funcread(amalgar);
        leftstr[i]=command;

        rightstr[i]=amalgar;
    }
    else if(command == "PRINT")
    {
        if(!(amalgar[amalgar.length()-1]=='"'&&amalgar[0]=='"'))
        {
            for(int i=0; i<amalgar.length(); i++)
                amalgar[i]=chartoupper(amalgar[i]);
        }
        funcprint(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "ADD")
    {
        //funcadd(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "SUB")
    {
        //funcsub(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "MULT")
    {
        //funcmult(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "DIVI")
    {
        funcdivi(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command == "DIVR")
    {
        //funcdivr(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command=="MOD")
    {
        //funcmod(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command=="RUNF")
    {
        funcrunf(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command=="LABEL")
    {
        //funclabel(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command=="IFGO")
    {
        //funcifgo(amalgar);
        leftstr[i]=command;
        rightstr[i]=amalgar;
    }
    else if(command=="END")
    {
        payan=0;
    }
    else
    {
        cout<<"dastore monaseb vared nashod";
        sign=false;
    }
    i++;
    return payan;
}

int main()
{

    cmdamalgar asli;
    string voroodi;
    string command,amalgar;
    int payan=1;
    while(payan)
    {
        cout<<"->"<<endl;
        getline(cin,voroodi);
        voroodi=space_aval(voroodi);//hazf fasele az aval , akhar khat
        voroodi=space_akhar(voroodi);//????????????????????????????????????????????جرا برداشته بودم ؟
        asli=dotikekonande(voroodi);
        amalgar=asli.amalgar;
        command=asli.command;
        command=space_akhar(command);
        amalgar=space_aval(amalgar);
        payan=command_check(command,amalgar);
    }
    return 0;

}



