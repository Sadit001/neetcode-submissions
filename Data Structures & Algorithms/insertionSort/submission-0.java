class Solution {
    public List<List<Pair>> insertionSort(List<Pair> pairs) {
        List<List<Pair>> result = new ArrayList<>();
        
        for (int i = 0; i < pairs.size(); i++) {
            int j = i - 1;
            while (j >= 0 && pairs.get(j).key > pairs.get(j + 1).key) {
                Pair temp = pairs.get(j);
                pairs.set(j, pairs.get(j + 1));
                pairs.set(j + 1, temp);
                j--;
            }
            
            List<Pair> currentSnapshot = new ArrayList<>();
            for (Pair p : pairs) {
                currentSnapshot.add(new Pair(p.key, p.value));
            }
            result.add(currentSnapshot);
        }
        
        return result;
    }
}