FROM maven:3-jdk-11-slim as build

WORKDIR /usr/app

COPY pom.xml .

RUN mvn -B dependency:go-offline

COPY src src

RUN mvn package -DskipTests

FROM tomcat:9.0.59

COPY --from=build /usr/app/target/*.war /usr/local/tomcat/webapps/
