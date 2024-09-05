void inversion(vector<pdd> &dots, pdd o, double r){ //center: o, power: r
  for(auto &x:dots)x=o+(x-o)*r/dot(x-o, x-o);
}
