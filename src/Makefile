all:
	@echo "Building"
	mkdir build || true
	cd build && cmake ..
	cd build && cmake --build . --parallel 8
	mkdir ../inst || true
	mkdir ../inst/libs || true
	cp build/libaler.dylib ale.so
	cp build/libaler.dylib ../inst/libs/ale.so

clean:
	@echo "Cleaning"
	rm ale.so

