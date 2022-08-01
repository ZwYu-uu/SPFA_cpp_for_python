#define inf 0x42

#include <pybind11/pybind11.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <iterator>
#include <list>
#include <set>
#include <functional>
#include <memory.h>

namespace py = pybind11;
 
class SPFA_instance
{
public:
    int n, s, t;
    double **graph;
    double *dis;
    int *pre;
    bool *visited;

    SPFA_instance(){}

    SPFA_instance(int n)
    {
        this->n = n;
        graph = new double *[n];
        *graph = new double [n*n];
        for (int i = 0; i < n; ++i)
            *(graph+i) = *graph + i*n;
        memset(*graph, inf, sizeof(double)*n*n);
        dis = new double [n];
        visited = new bool [n];
        pre = new int [n];
        memset(*graph, inf, sizeof(double)*n*n);
        memset(dis, inf, sizeof(double)*n);
        memset(visited, false, sizeof(bool)*n);
        memset(pre, -1, sizeof(int)*n);
    }

    ~SPFA_instance()
    {
        delete [] graph[0];
        delete [] graph;
        delete [] dis;
        delete [] visited;
        delete [] pre;
    }

    void InputAdjMat(int u, int v, double weight)
    {
        this->graph[u][v] = weight;
    }

    void SetSourceAndTank(int s, int t)
    {
        this->s = s;
        this->t = t;
    }

    void Solve()
    {
        std::queue<int> q;
        dis[this->s] = 0;
        q.push(this->s);
        int temp;
        this->visited[this->s] = true;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            this->visited[temp] = false;
            for(int i = 0; i < n; i++)
            {
                if(this->dis[i] > this->dis[temp] + this->graph[temp][i])
                {
                    this->dis[i] = this->dis[temp] + this->graph[temp][i];
                    this->pre[i] = temp;
                    if(!this->visited[i])
                    {
                        q.push(i);
                        this->visited[i] = true;
                    }
                }
            }
        }
    }

    double GetDistance()
    {
        return dis[this->t];
    }

    int GetPre(int node)
    {
        return pre[node];
    }
};

PYBIND11_MODULE(SPFA, m) {
    py::class_<SPFA_instance>(m, "SPFA_instance")
        .def(pybind11::init<>())
        .def(pybind11::init<int>())
        .def("InputAdjMat", &SPFA_instance::InputAdjMat)
        .def("SetSourceAndTank", &SPFA_instance::SetSourceAndTank)
        .def("Solve", &SPFA_instance::Solve)
        .def("GetDistance", &SPFA_instance::GetDistance)
        .def("GetPre", &SPFA_instance::GetPre);
}

