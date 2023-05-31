int compare(string s, string t) {
    int size1 = s.length();
    int size2 = t.length();
    
    int size = size1 <= size2 ? size1 : size2;
    
    for(int i=0; i<size; i++) {
        if(s[i] < t[i]) {
            return 1;
        }
        if(s[i] > t[i]) {
            return 0;
        }
    }
    
    return size1 >= size2 ? 0 : 1;
}

int solution(string s, string t) {
    int size1 = s.length();
    int size2 = t.length();
    int count = 0;
    for(int i=0;i<size1;i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            string sTemp = s.substr(0,0+i) + s.substr(i+1,i+1+size1-1);
            count += compare(sTemp,t);
        }
    }
    
    for(int i=0;i<size2;i++) {
        if(t[i] >= '0' && t[i] <= '9') {
            string tTemp = t.substr(0,0+i) + t.substr(i+1,i+1+size2-1);
            count += compare(s,tTemp);
        }
    }
    return count;
}


