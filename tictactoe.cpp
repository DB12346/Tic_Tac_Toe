#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int check_for_comp_win(int crr[][3],int f);
int check_for_safety(int brr[][3],char a);
int  check_for_win(int arr[][3]);
void show(int arr[][3]);
void copy(int brr[][3],int crr[][3])
{
   for(int i=0;i<3;i++)
   {
       for(int j=0;j<3;j++)
       {
           crr[i][j]=brr[i][j];
       }
   }
}
int check_for_one(int arr[][3],int k,char a)
{
    int t1,t2;
    int crr[3][3];
    copy(arr,crr);
    t1=check_for_win(crr);
    t2=check_for_win(crr);
    if(t1==1 && t2==1)
    {
        return 0;
    }
    if(t1==1 && t2==0 && k==0)
    {
        if(check_for_safety(crr,a)==0)
        {
            return 0;
        }
        else 
        return 1;
    }
    return 1;
}
int check_for_safety(int brr[][3],char a)
{  
    int crr[3][3];
   // copy(brr,crr);
   for(int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
          copy(brr,crr);
          // cout<<"before the function"<<" i is : "<<i<<" and j is "<<j<<endl;
          // cout<<"brr["<<i<<"]["<<j<<"]"<<"  is "<<brr[i][j]<<endl;

         if(crr[i][j]==2)
         {              
             //  cout<<" i is : "<<i<<" and j is "<<j<<endl;
               crr[i][j]=1;

               if (a=='y')
               {   
                   if(check_for_comp_win(crr,0)==1)
                   return 1;
               }
               else if(a=='n')
                { 
                    if(check_for_comp_win(crr,1)==1)
                    {       
                      // cout<<"came in comp win";               
                       //cout<<"came in comp win";               
                       if(check_for_one(crr,1,a)==1)
                        return 1;
                        else 
                        return 0;
                    }
                }
                                  // cout<<" the value of check_for_one(crr) is "<<check_for_one(crr)<<endl;
             if (check_for_one(crr,0,a)==0)
              {
                   return 0;
              }              
         }
      }
   }
   return 1;
}
int check_for_diago(int brr[][3],int k)
{  
    int count =0;
    for(int i=0;i<3;i++) 
    {
        if(brr[i][i]==k)
        {
          count++;
        }
    }
    if(count==3)
    return 1;
    else
    {    
        //cout<<"came in else ";
         count=0;  
       for(int j=2;j>=0;j--)
      {
          if(brr[2-j][j]==k)
          count++;       
      }   
       if(count==3)
       return 1;     
    }      
      return 0;
}
int check_for_col(int brr[][3],int k)
{ int count=0; 
   for(int j=0;j<3;j++)
   { count=0;
       for(int i=0;i<3;i++)
       {
           if(brr[i][j]==k)
            {
                count++;
            }
       }
       if(count==3)
       return 1;
   }
   //cout<<"came in col funct";
   return 0;
}
int check_for_row(int arr[][3],int k)
{
    int count=0;
    for(int i=0;i<3;i++)
    {   count=0;
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==k)
            {
              count++;
            }
        }
        if(count==3)
        return 1;
    }
   // cout<<"came in row function";
    return 0;
}
   void show(int arr[][3])
   {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
               cout<<arr[i][j]<<"| ";
            }
         cout<<endl;
            cout<<"-------";
            cout<<endl;
         
        }
        cout<<endl;
   }
   
   void  ask_for_input(int arr[][3])
   {
       int r,c;
      cout<<"Enter the row no: ";
      cin>>r;
      cout<<"Enter the col no: ";
      cin>>c;
      arr[r-1][c-1]=1;
                                            
   }
   
   int  check_for_win(int arr[][3])
    {
        int brr[3][3];
        //copy(arr,brr);
    
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {    copy(arr,brr);
                if(brr[i][j]==2)
                {
                       brr[i][j]=1;
                    if(check_for_row(brr,1)==1 ||check_for_col(brr,1)==1 ||check_for_diago(brr,1)==1)
                      
                      {   
                          arr[i][j]=0;
                         return 1;
                      }
                }
            }
        }
     //   cout<<"came till here";
        return 0;
    }
  int  check_for_comp_win(int arr[][3],int f)
    {
       int brr[3][3];
         //copy(arr,brr);
    
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {  
                copy(arr,brr);
                if(brr[i][j]==2)
                {
                    brr[i][j]=0;
                   // cout<<"came after brr[i][j]";
                    if(check_for_row(brr,0)==1 ||check_for_col(brr,0)==1 ||check_for_diago(brr,0)==1)
                      {  
                         // cout<<"check_for_row(brr,0) "<<check_for_row(brr,0)<<endl;
                        //  cout<<"check_for_col(brr,0)"<<check_for_col(brr,0)<<endl;
                       //   cout<<"check_for_diago(brr,0)"<<check_for_diago(brr,0)<<endl;
                          if(f==0)
                         arr[i][j]=0;
                         if(f==1)
                         arr[i][j]=1;
                         return 1;
                      }
                }
            }
        }
        return 0;
    }
 int main()
{
 
     int arr[3][3];
     
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<3;j++)
         arr[i][j]=2;
     }
   show(arr);
   char a;
   cout<<"do u wanna start y or n ";
  cin>>a;
  int count=0;
    
  if(a=='n')
  {
      arr[1][1]=0;
      show(arr);
      count=1;
                 
   } 
   while(count<9)
{
   
    int k=0;
   ask_for_input(arr);
   count++;
   if(count==9)
   cout<<"TIE"<<endl;
    show(arr);
    if(check_for_comp_win(arr,0)==1)
    { 
        show(arr);
        cout<<"HaHa I Beat U  :)";
        break;
    
    }
    else
    {
      //  cout<<"came in else statement";
    if(check_for_win(arr)==0)
    {
         // cout<<"came here ";
            int brr[3][3];
        //copy(arr,brr);
       for(int i=0;i<3;i++)
       {
           for(int j=0;j<3;j++)
           {  
                 
                copy(arr,brr);
               if(brr[i][j]==2)
                {   
                     brr[i][j]=0;
                 //  cout<<"check_for_safety(brr)"<<check_for_safety(brr,a)<<endl;
                    if(check_for_safety(brr,a)==1)
                    {
                       // cout<<"came in safe zone ";
                        arr[i][j]=0;
                        show(arr);
                        k=1;
                        count++;
                       
                    }
                }
                if(k==1)
                break;        
           }
           if(k==1)
           {    if(count==9)
               {
                   cout<<"TIE"<<endl;
               }
               break;
           }
       }    
            
     }
     else
     { show(arr);
        count++;
     }
  }
}

}