void Nhap(DATHUC &B, double heso, int somu) {
    DONTHUC* donthuc = new DONTHUC(heso, somu);
    Node* newNode = new Node(donthuc);

    if (B.head == nullptr) B.head = B.tail = newNode;
    else {
        Node* prev = nullptr;
        Node* cur = B.head;

        while (cur != nullptr && cur->data->somu > somu) {
            prev = cur;
            cur = cur->next;
        }

        if (cur != nullptr && cur->data->somu == somu) {
            cur->data->heso += heso;
            delete newNode;

            if (cur->data->heso == 0) {
                if (prev == nullptr) B.head = cur->next;
                else prev->next = cur->next;

                if (cur == B.tail) B.tail = prev;
                delete cur;
            }
        } else {
            if (prev == nullptr) {
                newNode->next = B.head;
                B.head = newNode;
            } else {
                newNode->next = cur;
                prev->next = newNode;
            }
            if (cur == nullptr) B.tail = newNode;
        }
    }
}

void Xuat(DATHUC B) {
    Node* cur = B.head;
    bool First = 1;

    while (cur != nullptr) {
        double heso = cur->data->heso;
        int somu = cur->data->somu;

        if (heso != 0) {
            if (!First) {
                if (heso > 0) cout << "+";
                else cout << "-";
            } else {
                if (heso < 0) cout << "-";
            }

            double HesoDuong = abs(heso);
            if (!somu || (HesoDuong != 1)) {
                if (HesoDuong == (int)HesoDuong) cout << (int)HesoDuong;
                else cout << HesoDuong;
            }

            if (somu > 0) {
                cout << "x";
                if (somu > 1) cout << "^" << somu;
            }

            First = 0;
        }

        cur = cur->next;
    }

    if (First) cout << "0";
}

double TinhDaThuc(DATHUC B, double x) {
    double res = 0;
    Node* cur = B.head;

    while (cur != nullptr) {
        double heso = cur->data->heso;
        int somu = cur->data->somu;
        res += heso * pow(x, somu);
        cur = cur->next;
    }

    return res;
}
