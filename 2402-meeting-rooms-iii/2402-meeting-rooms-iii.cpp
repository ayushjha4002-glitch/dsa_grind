class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        // Sort meetings according to starting time
        sort(meetings.begin(), meetings.end());

        // Available rooms -> smallest room number on top
        priority_queue<int, vector<int>, greater<int>> available;

        // Busy rooms -> (endTime, roomNumber)
        // First compare endTime, then roomNumber
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        // Initially all rooms are available
        for(int i = 0; i < n; i++) {
            available.push(i);
        }

        // Count how many meetings each room gets
        vector<int> count(n, 0);

        for(auto meeting : meetings) {

            long long start = meeting[0];
            long long end = meeting[1];

            // Make all rooms available whose meeting
            // has already finished
            while(!busy.empty() && busy.top().first <= start) {

                int room = busy.top().second;

                available.push(room);
                busy.pop();
            }

            // Case 1: At least one room is available
            if(!available.empty()) {

                // Get smallest room number
                int room = available.top();
                available.pop();

                // This room is now busy until 'end'
                busy.push({end, room});

                count[room]++;
            }

            // Case 2: No room is available
            else {

                // Get room which becomes free earliest
                auto [freeTime, room] = busy.top();
                busy.pop();

                // Meeting duration
                long long duration = end - start;

                // Meeting starts when this room becomes free
                long long newEnd = freeTime + duration;

                busy.push({newEnd, room});

                count[room]++;
            }
        }

        // Find room which hosted maximum meetings
        int ans = 0;

        for(int i = 1; i < n; i++) {
            if(count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};