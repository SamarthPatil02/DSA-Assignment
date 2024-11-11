/*
SAMARTH PATIL
ROLL NO : 23574
Title:  Graph- Shortest Path Algorithm

Problem Statement: Represent a graph of city using adjacency matrix /adjacency list. Nodes should represent the various landmarks 
and links should represent the distance between them. Find the shortest path using Dijkstra's algorithm from single source to all 
destination.


*/

#include<iostream>

#define max 20
using namespace std;

class graph
{

  int g[max][max], n, c[max], ch[max], min_dist, client_dist, visit_dist;
  char v[max], str[max][max], min_path[max], client_path[max],
    visit_path[max];
    //5000  2  4  10
    /*g[max][max]= adjacency matrix n= vertex  c[max]= stores weight
    ch[max]=checks node is visited or not
    min_dist=stores min distance
    v[max]=stores vertex
    str[max][max]=adjacency matrix of STP
    
    
    */
public:
graph (int m)
  {
    n = m;//vertex
    visit_dist = 0;
    client_dist = 0;
     min_dist = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	g[i][j] = 0;//adjacency matrix
  }


  void accept_v ();// accepts vertex
  void accept_e ();//accepts edges
  void display ();
  void dj_init (int);
  void dj_init ();
  void dj (char, char, int);//Dijkstras algo

};

void graph :: accept_v ()
{
  int i = 0;
  cout << "\n\t\t\tName of Cities";
  while (i < n){

  cout << "\nEnter Name of City : [" << i + 1 << "] :: ";
 cin >> v[i];
  i++;}

}


void graph::accept_e ()
{

  char ch;
  char v1, v2;
  int i, j, cst;//cst= weight
  for (i = 0; i < n; i++)
    for (j = i; j < n; j++)
      {
	if (i == j)
	  {
	    g[i][j] = 0;//assigning values to cell
	    continue;
	  }
	else
	cout << "\n\tRent between cities [" << v[i] << "][" << v[j] <<"]  :";
                 cin>>cst;
                 g[i][j]=g[j][i]=cst; }}// saving user inputed distance

void graph::display()
{
   int i, j;
   i=0;
   cout<<" \n ";
   while(i<n)
   {
   cout<<" \t "<<v[i];//prints vertex name
   i++;
   }
   for(i=0;i<n;i++)
   {
   cout<<" \n "<<v[i];
   for(j=0;j<n;j++)
      {
         cout<<" \t "<<g[i][j];// prints adjacency matrix
      }
      
   }
   
}



void graph::dj_init()
{
   int i,j;

	for(i=0;i<n;i++)
	{
		c[i]=9999;
		ch[i]=0;
		for(j=0;j<n;j++)
		{
			str[i][j]='-';//
		}
	}}

void graph::dj_init(int i){//
int j;
for(int j=0;j<n;j++)
	{
		str[i][j]='-';//
	}
   
}
  
void graph::dj(char s,char d,int f)//
{
	dj_init();
	int i,j,l,k,flag,min=999,cst=0;
	i=0;
	while(v[i]!=s)// traversing v[i] until s doesnot come
		i++;
	c[i]=0;// at first wt of s will be 0

	k=0;
	str[i][k]=v[i];//updating 	str[i][k]
	do
	{
		ch[i]=1;//visited node
		min=999;//at first min distance will be 999
		for(j=0;j<n;j++)
		{
			flag=0;
			cst=c[i]+g[i][j];// present distance + travelled distance
			if(g[i][j]!=0 && i!=j && cst<c[j])// cst should be less than c[i]
			{
				k=0;
				c[j]=cst;// updating c[i] value
				dj_init(j);
				while(flag==0)
				{
					str[j][k]=str[i][k];// updating adjacency matrix of STP
					k++;
					if(str[i][k]=='-')
						flag=1;// changing flag value
				}
				str[j][k]=v[j];
			}
		}


		for(l=0;l<n;l++)
		{
			if(c[l]<=min&&ch[l]==0)// comparing previously travelled  nd recent travelled dist.
			{
				min=c[l];// updating min val 
				i=l;
			}
		}

	}while(v[i]!=d);

	j=0;
	if(f==0)
		min_dist=c[i];//
	else
		client_dist=c[i];
	if(f==0)
		cout<<"\n\n\nMinimum Distance : "<<c[i]<<"\nShortest Path : ";
	while(str[i][j]!='-')
	{
		if(f==0)
			min_path[j]=str[i][j];
		if(f==0)
			cout<<" "<<str[i][j];
		j++;
	}
	min_path[j]='\0';
	cout<<"\n\n";
	j=1;
	while(str[i][j]!='-'&&f==1)
	{
		client_path[j-1]=str[i][j];
		j++;
	}
	client_path[j-1]='\0';
	cout<<"\n\n\n\nShortest Distance\n\n";//to print shortest path b/n
	for(int h=0;h<n;h++)
	{
		cout<<"\n "<<v[h]<<" "<<c[h]<<"\n\t";// prints distance to each node
		for(int m=0;m<n;m++)
		{
			cout<<" "<<str[h][m];
		}
	}
}
int main()
{
int n,ch;

char v1, v2;
cout<<"\nEnter Number of Cities :: ";

cin>>n;


graph g(n);



do

{

cout<<"\nEnter Your Choice :: \n1.Accept City Name\n2.Accept routes\n3.Display\n4.Shortest path\n5.Exit |";
cin>>ch;

switch(ch)

   { case 1: g.accept_v(); break;
   
   case 2: g.accept_e(); break;
   
   case 3: g.display(); break;
   
   case 4: cout<<"\nEnter Start Point :: ";
   
   cin>>v1; cout<<"\nEnter Destination :: ";
   cin>>v2;

   g.dj (v1,v2,0);
   
   break;
}
}while(ch!=5);

return 0;

}
