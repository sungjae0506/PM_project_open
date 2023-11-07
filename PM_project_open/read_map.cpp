#include "read_map.h"

vector<vector<int>> readMap(string file)
{
	fstream f(file);
	vector<vector<int>> arr;
	string s;
	int h, w;
	f >> h >> w;
	arr.resize(h);
	for (int i = 0; i < h; ++i)
		arr[i].resize(w);
	for (int i = 0; i < h; ++i)
	{
		f >> s;
		for (int j = 0; j < w; ++j)
			if (s[j] == '#')
				arr[i][j] = 1;
	}
	return arr;
}

Point indexToPoint(int i, int j, int h, int w, const Range &r)
{
	return Point(r.point0.x + (j * (r.point1.x - r.point0.x) / w), r.point1.y - (i * (r.point1.y - r.point0.y)) / h);
}

Lines vectorToLines(vector<vector<int>>& arr, const Range &r)
{
	Lines lines;
	int h = arr.size();
	int w = arr[0].size();
	int prev;

	for (int i = 0; i < h - 1; ++i)
	{
		prev = -1;
		for (int j = 0; j < w; ++j)
		{
			if (!(arr[i][j] == 0 && arr[i + 1][j] == 1)) // norm�� ����
			{
				if (j > prev + 1)
					lines.addLine(Line(indexToPoint(i + 1, prev + 1, h, w, r), indexToPoint(i + 1, j, h, w, r), Point(0, 1)));
				prev = j;
			}
		}
		if (w > prev + 1)
			lines.addLine(Line(indexToPoint(i + 1, prev + 1, h, w, r), indexToPoint(i + 1, w, h, w, r), Point(0, 1)));
		prev = -1;
		for (int j = 0; j < w; ++j)
		{
			if (!(arr[i][j] == 1 && arr[i + 1][j] == 0)) // norm�� �Ʒ���
			{
				if (j > prev + 1)
					lines.addLine(Line(indexToPoint(i + 1, prev + 1, h, w, r), indexToPoint(i + 1, j, h, w, r), Point(0, -1)));
				prev = j;
			}
		}
		if (w > prev + 1)
			lines.addLine(Line(indexToPoint(i + 1, prev + 1, h, w, r), indexToPoint(i + 1, w, h, w, r), Point(0, -1)));
	}

	for (int j = 0; j < w - 1; ++j)
	{
		prev = -1;
		for (int i = 0; i < h; ++i)
		{
			if (!(arr[i][j] == 0 && arr[i][j + 1] == 1)) // norm�� ����
			{
				if (i > prev + 1)
					lines.addLine(Line(indexToPoint(prev + 1, j + 1, h, w, r), indexToPoint(i, j + 1, h, w, r), Point(-1, 0)));
				prev = i;
			}
		}
		if (h > prev + 1)
			lines.addLine(Line(indexToPoint(prev + 1, j + 1, h, w, r), indexToPoint(h, j + 1, h, w, r), Point(-1, 0)));
		prev = -1;
		for (int i = 0; i < h; ++i)
		{
			if (!(arr[i][j] == 1 && arr[i][j + 1] == 0)) // norm�� ������
			{
				if (i > prev + 1)
					lines.addLine(Line(indexToPoint(prev + 1, j + 1, h, w, r), indexToPoint(i, j + 1, h, w, r), Point(1, 0)));
				prev = i;
			}
		}
		if (h > prev + 1)
			lines.addLine(Line(indexToPoint(prev + 1, j + 1, h, w, r), indexToPoint(h, j + 1, h, w, r), Point(1, 0)));
	}

	return lines;
}