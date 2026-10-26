class Solution {
    public void placequeen(List<List<String>> ans,List<StringBuilder> tans,int n,boolean[] ld,boolean[] rd,boolean[] col,int i){
        if(i==n){
            List<String> temp=new ArrayList<>();
            for(StringBuilder s:tans) temp.add(s.toString());
            ans.add(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(col[j] || ld[n-1+i-j] || rd[i+j]) continue;
            col[j]=true;
            ld[n-1+i-j]=true;
            rd[i+j]=true;
            tans.get(i).setCharAt(j,'Q');
            placequeen(ans,tans,n,ld,rd,col,i+1);
            col[j]=false;
            ld[n-1+i-j]=false;
            rd[i+j]=false;
            tans.get(i).setCharAt(j,'.');
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans=new ArrayList<>();
        List<StringBuilder> tans=new ArrayList<>();
        for(int i=0;i<n;i++){
            StringBuilder s=new StringBuilder();
            for(int j=0;j<n;j++) s.append('.');
            tans.add(s);
        }
        boolean[] ld=new boolean[2*n-1],rd=new boolean[2*n-1],col=new boolean[n];
        placequeen(ans,tans,n,ld,rd,col,0);
        return ans;
    }
}