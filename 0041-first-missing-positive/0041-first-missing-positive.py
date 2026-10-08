class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        s1=set(nums)
        ans = -1
        mx= max(s1)
        if mx<0:
            return 1
        for i in range(1,mx):
            if i in s1:
                continue
            else:
                ans=i
                break
        if ans==-1:
            return mx+1
        else:
            return ans


        