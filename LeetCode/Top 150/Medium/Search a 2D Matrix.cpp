bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int st = 1;
        int en = m * n;
        int mid ;
        while(st<=en){
            mid = (st+en)/2;

            int row = mid / n;
            if(mid%n==0)row--;
            int col = mid % n;
            if(mid%n==0)col = n;
            col = col - 1;

            if(matrix[row][col] == target)return true;
            else if(matrix[row][col] < target) st = mid + 1;
            else en = mid - 1;

        }

        return false;
        
    }
