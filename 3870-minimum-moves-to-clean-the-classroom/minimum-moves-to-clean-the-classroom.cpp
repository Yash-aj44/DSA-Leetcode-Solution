#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct State {
        int r;
        int c;
        int energy;
        int mask;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // Store positions of all litter
        vector<pair<int, int>> litter;

        int sr = -1, sc = -1;

        // Find S and L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // If there is no litter, we're already done
        if (k == 0) return 0;

        int allMask = (1 << k) - 1;

        /*
            visited[r][c][energy][mask]

            We flatten the 4D array into one vector.
            bool/char is used to save memory.
        */

        int masks = 1 << k;

        long long totalStates =
            1LL * m * n * (energy + 1) * masks;

        vector<char> visited(totalStates, false);

        auto getIndex = [&](int r, int c, int e, int mask) {

            return (((r * n + c) * (energy + 1) + e)
                    * masks + mask);
        };

        queue<State> q;

        // Student starts with full energy
        int startMask = 0;

        // In case S itself somehow corresponds to litter
        // (not possible according to the problem, but harmless)

        int startIndex = getIndex(sr, sc, energy, startMask);

        visited[startIndex] = true;

        q.push({sr, sc, energy, startMask});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            // BFS level = number of moves
            while (size--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int e = cur.energy;
                int mask = cur.mask;

                // All litter collected
                if (mask == allMask) {
                    return moves;
                }

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Cannot enter obstacle
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    /*
                        We need 1 energy to make a move.
                    */
                    if (e == 0) {
                        continue;
                    }

                    int newEnergy = e - 1;

                    /*
                        If we land on R, immediately
                        restore energy to maximum.
                    */
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int newMask = mask;

                    /*
                        Check whether this cell is litter.
                    */
                    for (int i = 0; i < k; i++) {

                        if (litter[i].first == nr &&
                            litter[i].second == nc) {

                            newMask |= (1 << i);
                            break;
                        }
                    }

                    int index =
                        getIndex(nr, nc, newEnergy, newMask);

                    if (!visited[index]) {

                        visited[index] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};