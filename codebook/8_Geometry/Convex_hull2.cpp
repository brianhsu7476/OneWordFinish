vector<int> hull(vector<pdd> &dots){ // n=1 => ans = {}
  if(dots.size()==1)return vector<int>(1, 0);
  if(dots.size()==2) return vector<int>({0, 1});
  vector<pair<pdd, int>> tmp;
  for(int i=0; i<dots.size(); i++)tmp.pb({dots[i], i});
  sort(tmp.begin(), tmp.end());
  vector<pdd> ans(1, tmp[0].X); vector<int> idx(1, tmp[0].Y);
  for(int ct=0; ct<2; ++ct, reverse(tmp.begin(), tmp.end()))
    for(int i=1, t=ans.size(); i<tmp.size(); ans.pb(tmp[i].X), idx.pb(tmp[i++].Y))
      while(ans.size()>t&&ori(ans[ans.size()-2], ans.back(), tmp[i].X)<=0)ans.pop_back(), idx.pop_back();
  ans.pop_back(), idx.pop_back(), ans.swap(dots);
  return idx;
}
