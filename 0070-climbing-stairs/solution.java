class Solution {
    public int climbStairs(int n) {
        n = n+1;
        double sqrt5 = Math.sqrt(5);
        double phi = (1 + sqrt5) / 2; // Golden Ratio
        double psi = (1 - sqrt5) / 2; // Conjugate of Golden Ratio

        int ans = (int) ((Math.pow(phi, n) - Math.pow(psi, n)) / sqrt5);
        return ans;

    }
}
