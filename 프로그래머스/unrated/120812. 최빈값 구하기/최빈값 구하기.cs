using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] array) {

    Dictionary<int, int> countDic = new Dictionary<int, int>();

    int max = 0;
    int maxKey = 0;
    bool isSame = false;

        for(int i = 0; i < array.Length;++i)
        {
            if (countDic.ContainsKey(array[i]))
            {
                countDic[array[i]]++;
            }
            else
            {
                countDic.Add(array[i], 1);
            }
        }

        foreach (KeyValuePair<int, int> KV in countDic)
        {
            if(max < KV.Value)
            {
                max = KV.Value;
                maxKey = KV.Key;
                isSame = false;
            }else if(max == KV.Value)
            {
                isSame = true;
            }
        }

        if (isSame) return -1;
        else return maxKey;
    
    }
}