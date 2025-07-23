/*
ID : 24006970
Name: Arissya Zahiera Binti Zulazman
Group: G1
BSF Graph
*/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void BFS(map<char, vector<char>>& graph, char start) {
    set<char> visited;      
    queue<char> q;          

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        char current = q.front();
        q.pop();
        cout << current << " ";  

       
        for (char neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    map<char, vector<char>> graph;
    graph['A'] = { 'B', 'C', 'D' };
    graph['B'] = { 'A', 'D', 'E' };
    graph['C'] = { 'A', 'D' };
    graph['D'] = { 'A', 'B', 'C', 'E' };
    graph['E'] = { 'B', 'D' };

    cout << "BFS starting from A: ";
    BFS(graph, 'A');
    return 0;
}
