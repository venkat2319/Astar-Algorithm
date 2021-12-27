" A* for Romanian Graph "
#include<iostream>
#include<vector>
#include<memory.h>
#include<stack>
#include<algorithm>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8
#define L 9
#define M 10
#define N 11
#define O 12
#define P 13
#define R 14
#define S 15
#define T 16
#define U 17
#define V 18
#define Z 19

using namespace std;

/*
*Estimation cost of possible optimal path from n node to target node
*/
int h[20] =
{ 366,0,160,242,161,
178,77,151,226,244,
241,234,380,98,193,
253,329,80,199,374 };


/*
*A node structure, node
*/
struct node
{
    int g;                              //The actual cost of the traversed path from the start node to the n node
    int h;                              //Estimation cost of possible optimal path from n node to target node
    int f;                              //Cost estimation function
    int name;
    node(int name, int g, int h)        //Constructor
    {
        this->name = name;
        this->g = g;
        this->h = h;
        this->f = g + h;
    };
    bool operator <(const node &a)const //Overloaded operator, sorted by f from small to large
    {
        return f < a.f;
    }
};


class Graph                             //Graph structure
{
public:
    Graph()
    {
        memset(graph, -1, sizeof(graph));//The graph is initialized to - 1
    }
    int getEdge(int from, int to)       //Get edge
    {
        return graph[from][to];
    }
    void addEdge(int from, int to, int cost)    //Add an edge
    {
        if (from >= 20 || from < 0 || to >= 20 || to < 0)
            return;
        graph[from][to] = cost;
    }
    
	void init(){                        //Graph initialization
        addEdge(O, Z, 71);
        addEdge(Z, O, 71);

        addEdge(O, S, 151);
        addEdge(S, O, 151);

        addEdge(Z, A, 75);
        addEdge(A, Z, 75);

        addEdge(A, S, 140);
        addEdge(S, A, 140);

        addEdge(A, T, 118);
        addEdge(T, A, 118);

        addEdge(T, L, 111);
        addEdge(L, T, 111);

        addEdge(L, M, 70);
        addEdge(M, L, 70);

        addEdge(M, D, 75);
        addEdge(D, M, 75);

        addEdge(D, C, 120);
        addEdge(C, D, 120);

        addEdge(C, R, 146);
        addEdge(R, C, 146);

        addEdge(S, R, 80);
        addEdge(R, S, 80);

        addEdge(S, F, 99);
        addEdge(F, S, 99);

        addEdge(F, B, 211);
        addEdge(B, F, 211);

        addEdge(P, C, 138);
        addEdge(C, P, 138);

        addEdge(R, P, 97);
        addEdge(P, R, 97);

        addEdge(P, B, 101);
        addEdge(B, P, 101);

        addEdge(B, G, 90);
        addEdge(G, B, 90);

        addEdge(B, U, 85);
        addEdge(U, B, 85);

        addEdge(U, H, 98);
        addEdge(H, U, 98);

        addEdge(H, E, 86);
        addEdge(E, H, 86);

        addEdge(U, V, 142);
        addEdge(V, U, 142);

        addEdge(I, V, 92);
        addEdge(V, I, 92);

        addEdge(I, N, 87);
        addEdge(N, I, 87);
	}

private:
    int graph[20][20];              
};

bool list[20];                          
vector<node> openList;                  
bool closeList[20];                     
stack<int> road;                        
int parent[20];                         

void A_star(int goal,node &src,Graph &graph)
{
    openList.push_back(src);
    sort(openList.begin(), openList.end());
    
    while (!openList.empty())
    {
        /*The node with the least cost*/
        node cur = openList[0];                    
        if (cur.name == goal)                      
            return;
        openList.erase(openList.begin());           
        list[cur.name] = false;                     
        closeList[cur.name] = true;                 
        
        /*Traversing child nodes*/
        for (int i = 0; i < 20; i++)
        {
            if (graph.getEdge(cur.name, i) != -1 && !closeList[i])      
            {
                if (list[i])                                                            {
                    int j=0;
                    for (int j=0; j<openList.size(); j++){ 
                        if (openList[j].name == i)  break;
                    }
                    /*Refresh node*/
                    int cost=cur.g+graph.getEdge(cur.name,i);
                    if (cost< openList[j].g)
                    {
                        openList[j].g = cost;                           
                        openList[j].f = cost + openList[j].h;           
                        parent[i] = cur.name;                           
                    }
                }
                else                                                                    {
                    node newNode(i, graph.getEdge(cur.name, i), h[i]);
                    parent[i] = cur.name;
                    openList.push_back(newNode);                       
                    sort(openList.begin(), openList.end());             
                    list[i]=true;
                }
            }
        }
    }
}

void print_result(Graph &graph)
{
    int p = openList[0].name;
    int lastNodeNum;
    road.push(p);
    while (parent[p] != -1)
    {
        road.push(parent[p]);
        p = parent[p];
    }
    lastNodeNum = road.top();
    int cost = 0;
    cout << "solution: ";
    while (!road.empty())
    {
        cout << road.top() << "-> ";
        if (road.top() != lastNodeNum)
        {
            cost += graph.getEdge(lastNodeNum, road.top());
            lastNodeNum = road.top();
        }
        road.pop();
    }
    cout << "end" << endl;
    cout << "cost:" << cost;
}
int main()
{
    Graph graph;
    graph.init();
    int goal = B;
    node src(A, 0, h[A]);
    list[A] = true;
    memset(parent, -1, sizeof(parent));
    memset(list, false, sizeof(list));
    A_star(goal, src, graph);
    print_result(graph);
    return 0;
}