singleton: builder.out
	g++ singleton.cpp -o singleton.out

builder.out: factory.out
	g++ builder.cpp -o builder.out

factory.out: adapter.out
	g++ factory.cpp -o factory.out

adapter.out:
	g++ adapter.cpp -o adapter.out

clean:
	rm *.out