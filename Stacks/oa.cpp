#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int min_time_to_complete_trainings(const std::vector<std::vector<int> >& trainings, std::vector<std::pair<int, int> >& prior_commitments, int K) {
    std::priority_queue<int, std::vector<int>, std::greater<int> >  heap;
    for (const auto& training : trainings) {
        for (int course_time : training) {
            heap.push(course_time);
        }
    }
    std::sort(prior_commitments.begin(), prior_commitments.end());
    int time = prior_commitments[0].first;
    for (const auto& commitment : prior_commitments) {
        if (time < commitment.first) {
            time = commitment.first;
        }
        time += commitment.second - commitment.first;
    }
    while (!heap.empty() && K > 0) {
        int time_taken = heap.top();
        heap.pop();
        if (time_taken + time <= 24) {
            time += time_taken;
        } else {
            K--;
            time = time_taken;
        }
    }
    return time;
}

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin >> N >> M;
        std::vector<std::vector<int> > trainings(N);
        for (int n = 0; n < N; ++n) {
            trainings[n].resize(M);
            for (int m = 0; m < M; ++m) {
                std::cin >> trainings[n][m];
            }
        }
        std::vector<std::pair<int, int > > prior_commitments;
        int P;
        std::cin >> P;
        prior_commitments.reserve(P);
        for (int p = 0; p < P; ++p) {
            int start, end;
            std::cin >> start >> end;
            prior_commitments.emplace_back(start, end);
        }
        int K;
        std::cin >> K;
        
        std::cout << min_time_to_complete_trainings(trainings, prior_commitments, K) << std::endl;
    }
    return 0;
}