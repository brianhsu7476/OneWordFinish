void reorder_polygon(vector<pdd> &P){
    int pos = 0;
    for(int i = 1; i < SZ(P); i++)
        if(P[i].Y < P[pos].Y || (P[i].Y == P[pos].Y && P[i].X < P[pos].X))
            pos = i;
    rotate(P.begin(), P.begin() + pos, P.end());
}
vector<pdd> Minkowski(vector<pdd> P, vector<pdd> Q){ // |P|,|Q|>=3
    reorder_polygon(P), reorder_polygon(Q);
    P.push_back(P[0]), P.push_back(P[1]);
    Q.push_back(Q[0]), Q.push_back(Q[1]);
    vector<pdd> result;
    int i = 0, j = 0;
    while(i < SZ(P) - 2 || j < SZ(Q) - 2){
        result.push_back(P[i] + Q[j]);
        auto c = cross(P[i + 1] - P[i], Q[j + 1] - Q[j]);
        if(c >= 0 && i < SZ(P) - 2) ++i;
        if(c <= 0 && j < SZ(Q) - 2) ++j;
    }
    return result;
}
