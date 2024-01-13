// Link : https://leetcode.com/problems/friends-of-appropriate-ages/description/

int numFriendRequests(vector<int>& ages) {
  int a[121] = {}, ans = 0;
  for (auto age : ages) ++a[age];
  for (auto i = 15, minAge = 15, sSum = 0; i <= 120; sSum += a[i], ans += a[i++] * (sSum - 1))
    while (minAge <= 0.5 * i + 7) sSum -= a[minAge++];
  return ans;
}