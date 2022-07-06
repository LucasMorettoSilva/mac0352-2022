# syntax=docker/dockerfile:experimental
FROM maven:3-jdk-11-slim as build

WORKDIR /usr/app

COPY pom.xml .

COPY src src

RUN --mount=type=cache,target=/root/.m2,rw mvn -B clean package -DskipTests

FROM tomcat:9.0.59
#FROM tomcat:9.0.62

COPY --from=build /usr/app/target/*.war /usr/local/tomcat/webapps/
