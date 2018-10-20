#include<stdio.h>        
#include<stdlib.h>

void dijkstras(int, int, int );

struct path
{
    struct path *front, *back;
    int vertex, distance;
}*start;

void main()
{
    int n, s, d;

    printf("\n Enter the number of vertex in the matrix: ");
    scanf("%d", &n);
    printf("\n Enter the starting vertex: ");
    scanf("%d", &s);
    printf("\n Enter the destination vertex: ");
    scanf("%d", &d);
    dijkstras(n, s, d);
    
}

void dijkstras(int n, int s, int d)
{
    // checking values
    int label[7], l=0;
    int distance[7][7] = {{0, 9526425, 9526425, 8, 2, 9526425, 9526425}, {7, 0, 1, 9526425, 9526425, 9526425, 9526425}, {3, 9526425, 0, 9526425, 4, 3, 9526425}, {2, 9526425, 9526425, 0, 1, 9526425, 9526425}, {9526425, 9526425, 9526425, 9526425, 0, 9526425, 2}, {9526425, 9526425, 9526425, 10, 4, 0, 7}, {9526425, 9526425, 9526425, 2, 9526425, 9526425, 0}};
    /*
    int distance [n][n], label[n];
    */ 
    int  choice = 0;
    int i, j,k, temp;
    struct path *newNode, *tempNode;
    int smallest[2];
    for(i = 0; i<n; i++)
    {
        distance[i][i] = 0;
    }
    /*
    printf("\nEnter the required distances between the vertices!");
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {   
            if( i !=j )
            {
                printf("\n Does there exist a distance between vertex %d and %d ?", i, j);
                printf("\nYes(1) / No(0) : ");
                scanf("%d", &choice);
                if(choice == 1)
                {
                    printf("\n Distance between vertex %d and %d :", i, j);
                    scanf("%d", &distance[i][j]);
                }
                else
                {
                    distance[i][j] = 9526425;
                }
            }
            
        }
    }

    */
    

    //Initialising the label array! 
    for(i=0; i<n; i++)
    {
        if(i == s)
        {
            label[i] = 0;
        }
        else
            label[i] = 9999999;
    }
   
    //Entering the first value into the path data structure
    newNode = (struct path *)malloc(sizeof(struct path));
    start = newNode;
    newNode -> back = NULL;
    newNode -> front = NULL;
    newNode -> vertex = s;
    newNode -> distance = 0;
    tempNode = newNode;



    /*
    Now the Algorithm from here on goes like this:-
    1. The last entry of the path vertex will be choosen 
    2. All its adjacent vertices will be searched 
    3. Simultaneously, temporary values for them will be given according to the dijkstras rule 
    4. The Catch here is:
        -> while the temporary values are being assigned, we also find the smallest one 
        -> this is done by using a one dimentional array smallest[2]
            -> smallest[0] will have the distance value, the smallest one 
            -> smallest[1] will have the vertex value 
        -> So in conclusion, by the end of assigning the temporary value, we will have the smallest amoung all of them 
        -> this will be made the permanenet value 
        -> the process of making the value permanent ( i.e. drawing a box aroung the distance value) is done 
           by adding it to the linked list path
    5. Once we add this, the process repeates i.e. find the adjacent vetices... and so on 
    6. This process continues till the permanent vertex chosen is the destination vertex
    */
   
   while(newNode -> vertex != d)
   {    
       
       i = newNode -> vertex;
       smallest[0] = 9999999; // Some really high valueto start off the comparisson
       for(j = 0; j<n; j++)
       {
           if(distance[i][j] != 9526425 && i != j)
           {
               // If there exists an edge, do updation -> min(old label of j, (old label of i + distance between i and j))
               temp = label[i] + distance[i][j];
               if(temp<label[j])
               {
                   label[j] = temp;
               }
               if(label[j] < smallest[0])
               {
                   smallest[0] = label[j];
                   smallest[1] = j;
               }
            }
       }
        //so when we come out of this for loop we will have the vertex of the smallest distance from the vertex i 
        // This vertex will be made the permanent vertex and added to the path!
        newNode = (struct path *)malloc(sizeof(struct path));
        tempNode -> front = newNode;
        newNode -> back = tempNode;
        newNode -> front = NULL;
        newNode -> vertex = smallest[1];
        newNode -> distance = smallest[0];
        tempNode = newNode;
        // Right now, the path has a new entry which has 
        // newNode -> vertex, which is the adjacent vertex of the previous permanent valued vertex 
        // newNode -> distance, it is the distance between the both !!!!

   }

   tempNode = start;
   do
   {
       printf("(vertex: %d, distance: %d)->  ",tempNode ->vertex, tempNode ->distance);
       tempNode = tempNode -> front;
   }while(tempNode -> front!=NULL);

   printf("\n");
}
