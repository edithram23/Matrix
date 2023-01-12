/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y, int z) 
{
	int max = x; 
	if (y > max) 
	{ 
		max = y;
	} 

	if (z > max) 
	{ 
		max = z;
	} 

	return max; 
}

int main()
{
    int m,n;
    cout<<"Enter the value of m,n :";
    cin>>m>>n;
    char s1[m],s2[n];
    cout<<"String 1 : ";
    cin>>s1;
    cout<<"String 2 : ";
    cin>>s2;
    //cout<<s1<<s2;
    int arr[m+1][n+1];
    int *parent[m+1][n+1];
    for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<1;j++)
                {
                        arr[i][j]=0;
                        arr[j][i]=0;
                        parent[i][j]=&arr[i][j];
                        parent[j][i]=&arr[j][i];
                }
        }
    for(int i=0;i<m+1;i++)
    {
            for(int j=0;j<n+1;j++)
                {
                    if(j==strlen(s2) || i == strlen(s1)){break;}
                    int val = max(arr[i][j+1],arr[i+1][j],arr[i][j]);
                        if(s1[i]==s2[j])
                            {
                                arr[i+1][j+1] = arr[i][j]+2;
                                parent[i+1][j+1] = &arr[i][j];
                                
                                
                            }
                        else
                            {
                                arr[i+1][j+1] = val-1;
                                if(val==arr[i][j+1])
                                {
                                    parent[i+1][j+1] = &arr[i][j+1];
                                }
                                else if(val==arr[i+1][j])
                                {
                                    parent[i+1][j+1] = &arr[i+1][j];
                                }
                                else if(val==arr[i][j])
                                {
                                    parent[i+1][j+1] = &arr[i][j];
                                }
                                
                                
                            }
                }
        }    
    char max[8];    
    int in=0,jn=0;   
    int max1=arr[m][n];
    for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
                {
                        cout<<arr[i][j]<<"   ";
                    if(i==m)
                        {
                            if(arr[i][j]>max1)
                            {
                                    in=i;
                                    jn=j;
                                    max1=arr[i][j];
                            }
                        } 
                }
            cout<<"\n";    
        }
        cout<<"\n";
     cout<<in<<" "<<jn;
    for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
                {
                        cout<<*parent[i][j]<<"   ";
                }
            cout<<"\n";    
        }    
    int s=8;    

    while(in!=0 || jn!=0)
    {
                            max[s-1]=arr[in][jn];
                                if(*parent[in][jn]==arr[in][jn-1])
                                {
                                   
                                   jn--;
                                }
                                else if(*parent[in][jn]==arr[in-1][jn])
                                {
                                    in--;
                                  
                                    
                                }
                                else if(*parent[in][jn]==arr[in--][jn--])
                                {
                                    in--;
                                    jn--;
                                }
                                                                     
        s--;
    }cout<<"\n\n\n";
    for (int i=0;i<8;i++)
    {
        cout<<max[i]<<" ";
    }
    return 0;
}
