build:
	gcc -o spam_detector spam_detector.c utils.c keyword_body.c

run:
	./spam_detector

clean:
	rm -rf spam_detector