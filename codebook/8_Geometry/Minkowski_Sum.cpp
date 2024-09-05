void rot(vector<pdd> &P){
    int j = 0;
    for(int i = 1; i < SZ(P); i++)
        if(P[i].Y < P[j].Y || (P[i].Y == P[j].Y && P[i].X < P[j].X)) j = i;
    rotate(P.begin(), P.begin() + j, P.end());
}
vector<pdd> Minkowski(vector<pdd> P, vector<pdd> Q){ // |P|,|Q|>=3
    rot(P), rot(Q); P.pb(P[0]), P.pb(P[1]); Q.pb(Q[0]), Q.pb(Q[1]);
    vector<pdd> result; int i = 0, j = 0;
    while(i < SZ(P) - 2 || j < SZ(Q) - 2){
        result.pb(P[i] + Q[j]);
        auto c = cross(P[i+1] - P[i], Q[j+1] - Q[j]);
        if(c >= 0 && i < SZ(P) - 2) ++i;
        if(c <= 0 && j < SZ(Q) - 2) ++j;
    }
    return result;
}
