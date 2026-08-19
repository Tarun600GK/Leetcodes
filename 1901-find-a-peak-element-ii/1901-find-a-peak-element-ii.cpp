class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = n - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Find maximum element in middle column
            int maxRow = 0;

            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Current element
            int current = mat[maxRow][mid];

            // Check left and right
            int leftValue = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int rightValue = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;

            // Peak found
            if (current > leftValue && current > rightValue) {
                return {maxRow, mid};
            }

            // Bigger element on left
            if (leftValue > current) {
                right = mid - 1;
            }

            // Bigger element on right
            else {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};