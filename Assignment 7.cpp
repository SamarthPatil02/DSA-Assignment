/*DSA ASSIGN NO.7
*Name: SAMARTH PATIL
*Roll no. 23574[s4]
*Problem Statement:
*Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should 
*represent the various departments/institutes and links should represent the distance between them. 
*Find minimum spanning tree
*a) Using Kruskal’s algorithm.
*b) Using Prim’s algorithm.
*/
#include<iostream>
using namespace std;
class graph
{
    private:
               int **AL;  //pointer to pointer var  address of **AL is saved into *AL
               int no;// to store variables
               int *visit,*source,*dist; //array
   public:
              void create();     // to create adjacency matrix       
            void prim();  // to perform prims algo
            int min_index(); // to find min index
            int check();// to check 
    
};

void graph::create()
{
    int i,j,con,ch=1,choice=2;
    cout<<"\n\t ENTER NO OF VERTICES => ";
    cin>>no;//                                  0     1    2
    AL=new int*[no];                // 0        00   01   02
    for(i=0;i<no;i++)//                1        10   11   12   
        *(AL+i)=new int[no]; //         2       20   21   22
    cout<<"\n\t INITIAL MATRIX  => \n";//    
    for(i=0;i<no;i++)//                      
    {//                                      
       for(j=0;j<no;j++)
       {
               *(*(AL+i)+j)=100;  // assigning value to adjacency matrix
       }
       *(*(AL+i)+i)=0;
    }
        
    for(i=0;i<no;i++)
    {
       for(j=0;j<no;j++)
       {
               cout<<"\t"<<*(*(AL+i)+j);  // priting initial adjacency matrix  
       }
       cout<<"\n";
    }
    
    cout<<"\n\t TYPE OF GRAPH \n\t\t\t1.DIRECTED GRAPH\n\t\t\t2.UNDIRECTED GRAPH\n\t\t\tENTER CHOICE => ";
    cin>>choice;
    for(j=0;j<no;j++)
    {
           ch=1;
           while(ch)
           {
           cout<<"\n\tENTER connection of "<<j<<" => "; // taking connection from user
        cin>>con;
        cout<<"\n\tENTER DISTACE FROM "<<j<<" TO "<< con <<" => ";
        if(*(*(AL+j)+con)==100)
           {            
                    cin>>*(*(AL+j)+con); //taking wt from user
                    if(choice==2)   //for undirected graph
                    *(*(AL+con)+j)=*(*(AL+j)+con); //assign same value to cell having same row nd column
        }
        else
        {
                cout<<"\n\t distace already insert ";
        }
               cout<<"\n\t DO YOU WANT TO ADD CONNECTION (0.NO 1.YES)=> ";
               cin>>ch;
        }
     }
    cout<<"\n\t\n";
    for(i=0;i<no;i++)
    {
       for(j=0;j<no;j++)
       {
               cout<<"\t";
            cout<<*(*(AL+i)+j);  // print updated matrix
       }   
       cout<<"\n";
    }
}


int graph::min_index()
{
    int min=99,i,k;
    for(i=0;i<no;i++)
    {
        if(dist[i]<min && visit[i]==0)//checks  unvisited and minimum node
        {
            min=dist[i];  // save  min wt to min var
            k=i;      // save node to k
        }
    }
    
    return k;// returning vertx
}



int graph::check() // for checking node is visited or not
{
    int i;
    for(i=0;i<no;i++)
    { 
        if(visit[i]==0) // if visit[i]==0 means node is already visited
        {
            return 1;
        }
    }
    
    return 0;
}

void graph::prim()
{
    int min,k=0,j=0,count1=2,l=0,i;
    visit=new int();//to check graph is visited or not
    source=new int();//parent 
    dist=new int();//wt
    for(i=0;i<no;i++)
    {
       *(visit+i)=0;   // assigning 0 vlue to all indices   
       *(source+i)=0; // assigning 0 vlue to all indices       
       *(dist+i)=100;// assigning 100 vlue to all indices  
       *(dist+k)=0; // assigning 0 vlue to all indices  
    }
    while(check()) // if node is visied
    {
            *(visit+k)=1; // assign 1 value to that node
            for(i=0;i<no;i++) // traverse all node
            {
              if(*(*(AL+k)+i)!=0) //if node is not pointing to itself 
              {
              
                if(*(dist+i)>=*(*(AL+k)+i)&&*(visit+i)==0) //if distance is greater than
                  {                                // value in adjacency matrix nd node is not visited
                      //cout<<"\n\t =>"<<i;
                       *(dist+i)=*(*(AL+k)+i); //update values inside dist array 
                    *(source+i)=k; // after updatation , write parent of that node to source
                }     //k is parent 
             }
              }
              
           
            
            
            
            k=min_index(); // check for min wighted node
            cout<<"\n\t\t min index => "<<k;
            cout<<"\n\t dist";
            for(i=0;i<no;i++)// print all arrays
            {
                  cout<<"\t "<<*(dist+i);   
            }
                  cout<<"\n\t vist";
            for(i=0;i<no;i++)
            {
                  cout<<"\t "<<*(visit+i);   
            }
              cout<<"\n\t source";
            for(i=0;i<no;i++)
            {
                  cout<<"\t "<<*(source+i);   
            }
            
        }
}




int main()
{
    graph G;// obkect of graph class
    G.create();
    G.prim();
    return 0;
}
