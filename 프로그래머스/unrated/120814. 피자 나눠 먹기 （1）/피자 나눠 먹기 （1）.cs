using System;

public class Solution {
    public int solution(int n) {
        int pizza = n/7;
        if(n > pizza * 7) pizza++;
        return pizza;
    }
}