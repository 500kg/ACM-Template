
const int maxn = 1e6 + 50;
bool vis[maxn];
int tot, phi[maxn], prime[maxn];
void CalPhi(int n)
{
	memset(vis, 0, sizeof(vis));
	phi[1] = 1;
	tot = 0;
	for (int i = 2; i < n; i++)
	{
		if (!vis[i])
			prime[tot++] = i, phi[i] = i - 1;
		for (int j = 0; j < tot; j++)
		{
			if (i * prime[j] > n) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}