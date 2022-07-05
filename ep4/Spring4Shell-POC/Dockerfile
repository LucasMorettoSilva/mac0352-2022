FROM maven:3-jdk-11-slim as build

ENV POM pom.xml

WORKDIR /usr/app

COPY ${POM} pom.xml

RUN mvn -B dependency:go-offline

COPY src src

RUN mvn package -DskipTests

FROM tomcat:9.0.59
#FROM tomcat:9.0.62

COPY --from=build /usr/app/target/*.war /usr/local/tomcat/webapps/
