# DSA Advance-Assignment3

Họ và tên: Nguyễn Đăng Khoa

Lớp: ATTN2024

MSSV: 24520825

## Kiểm Kê 2	
Bài này chúng ta viết hai hàm sort theo yêu cầu đề bài: giảm dần theo số lượng từng loại hàng, nếu số lượng bằng nhau thì in theo mã số tăng dần. 

```C++
vector <pair<int, string>> candidates; // first là số lần xuất hiện của second

// giảm dần theo số lượng từng loại hàng
bool cmp1(string a, string b) {
    if (sz(a) != sz(b)) return sz(a) < sz(b);
    return a < b;
}

// nếu số lượng bằng nhau thì in theo mã số tăng dần
bool cmp2(const pair<int, string> &a, const pair<int, string> &b) {
    if (a.fi != b.fi) return a.fi > b.fi;
    if (sz(a.se) != sz(b.se)) return sz(a.se) < sz(b.se);
    return a.se < b.se;
}
```
## Binary Search 2	
Bài này để giải quyết các truy vấn một cách nhanh chóng thay vì lưu mảng $a$ một cách bình thường bây giờ chúng ta sẽ lưu thêm second là vị trí của chúng trước khi sort. 

Sau đó sort lại, rồi chặt nhị phân để giải quyết các truy vấn:
- Nếu x = 1, thì phải in ra vị trí đầu tiên xuất hiện y trong dãy A. Nếu không có thì in ra -1.
- Nếu x = 2, thì phải in ra vị trí cuối cùng xuất hiện y trong dãy A. Nếu không có thì in ra -1

```C++
pair <int, int> a[N]; // first là giá trị của mảng a, second là vị trí của mảng a trước khi sort

// TH1: x = 1
int L = 1, R = n, res = -1;
while (L <= R) {
    int mid = (L + R) >> 1;

    if (a[mid].fi >= x) {
        if (a[mid].fi == x) res = a[mid].se;
        R = mid - 1;
    } else L = mid + 1;
}

cout << res << endl;

// TH2: op = 2 
int L = 1, R = n, res = -1;
while (L <= R) {
    int mid = (L + R) >> 1;

    if (a[mid].fi <= x) {
        if (a[mid].fi == x) res = a[mid].se;
        L = mid + 1;
    } else R = mid - 1;
}

cout << res << endl;
```

## khangtd.DetectVirusin2D	

Bài này vì đề bài yêu cầu check cái xâu nó chỉ từ 2 - 10 kí tự nên ban đầu chúng ta sẽ sinh toàn bộ xâu có thể xong sau đó đẩy nó vào một cái vector rồi check nó bằng BinarySearch hoặc có thể dùng set, map, ... 

```C++
// Sinh toàn bộ xâu 
rep(i, 1, n) rep(j, 1, m) {
    string s;
    rep(k, j, min(j + 9, m)) {
        s += a[i][k];
        if (sz(s) >= 2) X.push_back(s);
    }
}

rep(j, 1, m) rep(i, 1, n) {
    string si;
    rep(k, i, min(i + 9, n)) {
        si += a[k][j];
        if (sz(si) >= 2) X.push_back(si);
    }
}

// Sắp xếp và loại bỏ các phần tử giống nhau
sort(all(X));
X.erase(unique(all(X)), X.end());

// Nếu nó nằm trong vector thì in ra 1 ngược lại in 0 
while (q-- ) {
    string x; cin >> x;
    cout << (binary_search(all(X), x) == 0 ? 0 : 1);
}
```
## khangtd.XepHang2	

Bài toán tương tự bài toán LinkedList: 
- Thầy giáo gọi = Xóa node 
- Bạn đó đứng ở đầu = Thêm Node vào đầu danh sách 

```C++
// Duy trì First, Last là 2 node phead, ptail
int First = 1, Last = n; 

// nxt[i], pre[i] liền trước, liền sau i 
nxt[1] = 2;
pre[n] = n - 1;

rep(i, 2, n) {
    pre[i] = i - 1;
    nxt[i] = i + 1;
}

rep(i, 1, m) {
    int x; cin >> x;

    if (x != First) {
        int preX = pre[x];
        int nxtX = nxt[x];

        // Xóa node  
        if (preX) nxt[preX] = nxtX;
        if (nxtX) pre[nxtX] = preX;

        if (x == Last) Last = preX;

        // Set node X đứng ở đầu  
        pre[x] = 0;
        nxt[x] = First;

        pre[First] = x;
        First = x;
    }

    cout << Last << " ";
}
```
## khangtd.XepHang	

Tương tự bài trên nhưng ở đầy yêu cầu in ra cả dãy, sau khi thầy giáo đã kêu hết.

```C++
int cur = First;
while (cur >= 0 && cur <= n) {
    cout << cur << ' ';
    cur = nxt[cur];
}
```