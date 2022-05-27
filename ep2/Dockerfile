FROM gcc as build

WORKDIR /usr/src/app

COPY . ./

RUN make clean && make

FROM ubuntu as server

WORKDIR /usr/src/app

ENV PORT=8080

COPY --from=build /usr/src/app/bin/server ./

RUN chmod 777 ./server

EXPOSE $PORT

CMD ./server ${PORT}

FROM ubuntu as client

WORKDIR /usr/src/app

ENV SERVER_PORT=8080 PORT=9080

COPY --from=build /usr/src/app/bin/client ./

RUN chmod 777 ./client

EXPOSE $PORT

CMD ./client ep2-server ${PORT}
