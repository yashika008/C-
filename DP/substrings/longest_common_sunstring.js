

class lcs{
    countWays(str1, str2){
        const n1 = str1.length;
        const n2 = str2.length;
        
        const dp = Array.from({length : n1+1} , () => Array(n2+1).fill(0)); 
        let ans  = 0;

        for(let i = 1;i <= n1;i++){
            for(let j = 1;j <= n2;j++){
                if(str1[i-1] === str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                ans = Math.max(ans, dp[i][j]);}
                else
                dp[i][j] = 0;
            }
        }
        return ans;
    }
};

const s1 = "abcjklp";
const s2 = "acjkp";

const sol = new lcs();

console.log(sol.countWays(s1,s2));