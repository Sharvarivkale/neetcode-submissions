/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> starts, ends;
        starts.reserve(n);
        ends.reserve(n);
        for (auto& it : intervals) {
            starts.push_back(it.start);
            ends.push_back(it.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0, maxRooms = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            // free every room whose meeting ended at or before this start
            while (j < n && ends[j] <= starts[i]) {
                j++;
                rooms--;
            }
            rooms++;
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};
