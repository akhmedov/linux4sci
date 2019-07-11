// https://github.com/algosolver01/algorithms/tree/master/Сломанный%20калькулятор

#include <iostream>
using namespace std;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAXNUM 1000

int DP[MAXNUM];

template <typename T> void print (T* array, int size) 
{
    for (int i = 0; i < size; i++)
        cout << array[i] << ' ';
    cout << endl;
}

int shortest_way (char* oper, int oper_size, int* num, int num_size, int goal, int max_path)
{
    for (int i = 0; i < MAXNUM; i++) DP[i] = 0;
    for (int i = 0; i < num_size; i++) DP[num[i]] = 1;

    print(DP, 50);

    for (int i = 1; i < MAXNUM; i++) {
        if (DP[i]) {
            for (int n = 0; n < num_size; n++) {
                int next = i * 10 + num[n];
                if (next < MAXNUM) DP[next] = DP[i] + 1;
            }
        }
    }

    print(DP, 50);
    if (DP[goal]) return DP[goal];

    for (int o = 0; o < oper_size; o++) {
        for (int n = 0; n < num_size; n++) {
            for (int id = 0; id < MAXNUM; id++) {

                if (DP[id] == 0) continue;
                int next_id = id;

                switch (oper[o]) {
                    case '+': next_id += num[n]; break;
                    case '*': next_id *= num[n]; break;
                    case '-': next_id -= num[n]; break;
                    case '/': next_id /= num[n] ? num[n] : 1; break;
                }

                if (next_id >= 0 && next_id < MAXNUM) {
                    if (DP[next_id] == 0) DP[next_id] = DP[id]+2;
                    else DP[next_id] = MIN(DP[next_id], DP[id]+2);
                }

            }
            cout << oper[o] << num[n] << " -> "; print(DP, 50);
        }
    }

    if (DP[goal]) DP[goal] += 1;
    else DP[goal] -= 1;

    return (max_path < DP[goal]) ? -1 : DP[goal] ;
}

int main ()
{
    freopen("23_samsung_in.txt", "r", stdin);

    int num_size, num[10], oper_size, max_path, goal;
    char oper[4];

    cin >> num_size;
    for (int i = 0; i < num_size; i++) cin >> num[i];
    
    cin >> oper_size;
    for (int i = 0; i < oper_size; i++) cin >> oper[i];

    cin >> max_path >> goal;

    cout << "Numbers: "; print (num, num_size);
    cout << "Operats: "; print (oper, oper_size);
    cout << "Goal: " << goal << endl;

    int path = shortest_way(oper, oper_size, num, num_size, goal, max_path);
    cout << path << endl;

    return 0;
}
