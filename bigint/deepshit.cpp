bigint bigint::add(const bigint& left, const bigint& right) {
	size_t i, size_ = max_size_t(left.size, right.size) + 1;
	char ik = static_cast<char>(left.neg == right.neg);
	char* data_;
	bigint res;
	bool is_diff_pos = true;
	try {
		data_ = new char[size_];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (i = 0; i < size_; ++ i)
		data_[i] = 0;
	for (i = 0; i < left.size; ++ i)
		data_[i] += left.data[i];
	for (i = 0; i < right.size; ++ i)
		data_[i] += (2*ik-1) * right.data[i];
	for (i = 0; i < size_ - 2 && data_[size_ - 2 - i] == 0; ++ i);
	if (data_[size_ - 2 - i] < 0  || (i == size_ - 2 && data_[0] == 0 && left.neg && left.neg != right.neg)) {
		is_diff_pos = false;
		for (i = 0; i < size_ - 1; ++ i)
			data_[i] = - data_[i];
	}
	for (i = 0; i < size_ - 1; ++ i) {
		if ((-ik*2+1) * data_[i] < -ik*9) {
			data_[i] += (-ik*2+1) * 10;
			data_[i + 1] += (ik*2-1);
		}
	}
	res.data = data_;
	for (i = 0; size_ - 1 - i > 0 && data_[size_ - 1 - i] == 0; ++ i);
	res.size = size_ - i;
	res.neg = is_diff_pos == left.neg;
	return res;
}
bigint bigint::sub(const bigint& left, const bigint& right) {
	bigint op_right (right);
	op_right.neg = !op_right.neg;
	return add(left, op_right);
}

/*
bigint bigint::add(const bigint& left, const bigint& right) {
	size_t size_;
	char* data_;
	bigint res;
	
	size_ = max_size_t(left.size, right.size) + 1;
	
	try {
		data_ = new char[size_];
	} catch (...) {
		cerr << "Memory allocation error" << endl;
		exit(1);
	}
	for (size_t i = 0; i < size_; ++ i) {
		data_[i] = 0;
	}
	
	if (left.neg == right.neg) {
		for (size_t i = 0; i < left.size; ++ i)
			data_[i] += left.data[i];
		for (size_t i = 0; i < right.size; ++ i)
			data_[i] += right.data[i];
		
		for (size_t i = 0; i < size_ - 1; ++ i)
			if (data_[i] > 9) {
				data_[i] -= 10;
				data_[i + 1] ++;
			}
		
		res.data = data_;
		res.size = size_ - 1 + data_[size_ - 1];
		res.neg = left.neg;
	} else {
		for (size_t i = 0; i < left.size; ++ i)
			data_[i] += left.data[i];
		for (size_t i = 0; i < right.size; ++ i)
			data_[i] -= right.data[i];
		
		bool abs_diff_pos = true;
		for (size_t i = 0; i < size_ - 1; ++ i)
			if (data_[size_ - 2 - i] != 0) {
				abs_diff_pos = data_[size_ - 2 - i] > 0;
				break;
			}
		if (!abs_diff_pos)
			for (size_t i = 0; i < size_ - 1; ++ i)
				data_[i] = - data_[i];
		
		for (size_t i = 0; i < size_ - 1; ++ i)
			if (data_[i] < 0) {
				data_[i] += 10;
				data_[i + 1] --;
			}
		
		res.data = data_;
		
		size_t i = 0;
		while (size_ - 1 - i > 0 && data_[size_ - 1 - i] == 0)
			++ i;
		res.size = size_ - i;
		
		res.neg = abs_diff_pos == left.neg;
	}
	
	return res;
}*/
