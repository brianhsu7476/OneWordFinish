struct matrix { //m variables, n equations
  int n, m;
  fraction M[MAXN][MAXN + 1], sol[MAXN][MAXN] = {};
  int piv[MAXN] = {};
  bool is_piv[MAXN] = {};
  int solve() { //-1: inconsistent, >= 0: matrix rank
    for (int i = 0; i < n; ++i) {
      while (piv[i] < m && !M[i][piv[i]].n) ++piv[i];
      if (piv[i] == m) continue;
      is_piv[piv[i]] = true; 
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        fraction tmp = -M[j][piv[i]] / M[i][piv[i]];
        for (int k = 0; k <= m; ++k) M[j][k] = tmp * M[i][k] + M[j][k];
      }
    }
    int rank = 0;
    for (int i = 0; i < n; ++i) {
      while (piv[i] < m && !M[i][piv[i]].n) ++piv[i];
      if (piv[i] == m && M[i][m].n) return -1;
      else if (piv[i] < m) ++rank, sol[0][piv[i]] = M[i][m] / M[i][piv[i]];
    }
    int idx = 1;
    for(int j = 0; j < m; j++) {
      if(is_piv[j]) continue;
      sol[idx][j] = 1;
      for(int i = 0; i < n; i++) {
        sol[idx][piv[i]] = sol[0][piv[i]] - M[i][j] / M[i][piv[i]];
      }
      idx++;
    }
    return rank;
  }
};
