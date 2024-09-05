// center: o, power: r
void inversion(vector<pdd> &dots, pdd o, double r) {
  for(auto &x: dots) {
    double dis = dot(x - o, x - o);
    x = o + (x - o) * r / dis;
  }
}
