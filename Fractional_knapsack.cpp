/// recursive dp ///////

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>values,vector<int>weights,int n,int w,vector<vector<int>>&dp)
{
	if(n == 0 || w == 0)
	{
		return 0;
	}

	if(dp[n][w] != -1)return dp[n][w];
	//pick
	if(weights[n-1] <= w)
	return dp[n][w] = max((values[n-1] + solve(values,weights,n-1,w-weights[n-1],dp)),(solve(values,weights,n-1,w,dp)));

	return dp[n][w] = solve(values,weights,n-1,w,dp);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// knapsack ->cap = W
	// N items : weight,value
	// maxprofit ??

	vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
	return solve(values,weights,n,w,dp);
}


///// ********* tabulation ********* /// Bottom up Approach /// 

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// knapsack ->cap = W
	// N items : weight,value
	// maxprofit ??

	vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
	// base condition -> initialization
	for(int wt = 0; wt <= w; wt++)
	{
		dp[0][wt] = 0;
	}
	for(int ind = 0; ind <= n; ind++)
	{
		dp[ind][0] = 0;
	}
	// recursive call to iterative
	for(int ind = 1; ind <= n; ind++)
	{
		for(int wt = 1; wt <= w; wt++)
		{
			if(weights[ind-1] <= wt)
			dp[ind][wt] = max((values[ind-1] + dp[ind-1][wt-weights[ind-1]]),(dp[ind-1][wt]));

			else
			dp[ind][wt] = dp[ind-1][wt];

		}
	}
	return dp[n][w];
}
