long long solution(vector<int> arr) {
    long long count = 0, prevCount = 0;
    long long first = 0, second = 1;
    int inc = 0, dec = 0;
    while(second < arr.size()) {
        if(arr[first] < arr[second]) {
            count++;
            if(dec == 1) {
                count++;
                count += prevCount;
                prevCount += 1;
            } else {
                prevCount = 0;
            }
            inc = 1;
            dec = 0;int count = 0;
        } else if(arr[first] > arr[second]) {
            count++;
            if(inc == 1) {
                count++;
                count += prevCount;
                prevCount += 1;
            } else {
                prevCount = 0;
            }
            inc = 0;
            dec = 1;
            
        } else {
            inc = 0;
            dec = 0;
        }
        first++;
        second++;
    }
    return count;
}
