#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int solution(string begin, string target, vector<string> words);
int main() {
    vector<string> words = { "hot","dot","dog","lot","log" };
    cout << solution("hit","cog",words);

}
int solution(string begin, string target, vector<string> words) {
    bool visit[50] = { false, };
    queue<pair<string,int>> q;
    q.push({ begin,0 });
    while (!q.empty()) {
        string word = q.front().first;
        int turn = q.front().second;
        int size = begin.size();
        q.pop();
        //�˻����
        if (!word.compare(target)) return turn;
        for (int i = 0; i < words.size(); i++) {
            if (visit[i] == true) continue;
            int count = 0;
            for (int j = 0; j < size; j++) {
                if (word[j] != words[i][j]) {
                    if (++count > 2) break;
                }
            }
            if (count == 1) {
                q.push({ words[i],turn + 1 });
                visit[i] = true;
            }
        }
    }
    return 0;
}