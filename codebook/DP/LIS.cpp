/*LIS 最長遞增子序列*/
void LIS() {
	for (int i = 0; i < n; i++) length[i] = 1;
	for (int j = 0; j < n; j++) {
		for (int i = j + 1; i < n; i++)
			if (s[j] < s[i])length[i] = max(length[i], length[j] + 1);
	}

	int l = 0;
	for (int i = 0; i < n; i++) {
		l = max(length[i], l);
	}
	cout << l;
}