vector<ll> dijkstra(vector<vector<pair<ll, ll>>>& graph, ll n, ll k) {
    priority_queue<pair<ll, ll>> pq;
    vector<ll> timeToNode(n + 1, 1e9);
    timeToNode[k] = 0;
    pq.push({0, k});
        
    while (!pq.empty()) {
        ll currTime = pq.top().first;
        ll currNode = pq.top().second;
        pq.pop();
        
         for (auto i: graph[currNode]) {
            if (timeToNode[i.second] > currTime + i.first) {
                timeToNode[i.second] = currTime + i.first;
                pq.push({timeToNode[i.second], i.second});
            }
        }
    }
        
    ll timeForAll = 0;
    for (ll i = 1; i <= n; i ++) {
        timeForAll = max(timeForAll, timeToNode[i]);
    }
        
    return timeToNode;
}
