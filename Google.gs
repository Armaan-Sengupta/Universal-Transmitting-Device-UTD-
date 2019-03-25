/*function doGet(e) {
  function doPost(e) {
    var french = LanguageApp.translate(e, 'en', 'fr');
  Logger.log(french);
  return french
  
}
 
var french = doPost(e)

  return ContentService.createTextOutput(french);

}

function doPost(e) {
  return ContentService.createTextOutput("hello");

};*/

function doGet(e) {
  
  if(typeof e !== 'undefined')
    return ContentService.createTextOutput(JSON.stringify(e.parameter));
  
}

function doPost(e) {
  
  if(typeof e !== 'undefined')
    return ContentService.createTextOutput(JSON.stringify(e.parameter));
  
}

function testPOST() {
  
  var url = ScriptApp.getService().getUrl();
  
  var payload =
      {
        "name" : "labnol",
        "blog" : "ctrlq",
        "type" : "post",
      };
  
  var options =
      {
        "method"  : "POST",
        "payload" : payload,   
        "followRedirects" : true,
        "muteHttpExceptions": true
      };
  
  var result = UrlFetchApp.fetch(url, options);
  
  if (result.getResponseCode() == 200) {
    
    var params = JSON.parse(result.getContentText());
    
    Logger.log(params.name);
    Logger.log(params.blog);
    
  }
  
}

function testGET() {
  
  var queryString = "?name=labnol&blog=ctrlq&type=get";
  
  var url = ScriptApp.getService().getUrl() + queryString;
  
  var options =
      {
        "method"  : "GET",   
        "followRedirects" : true,
        "muteHttpExceptions": true
      };
    
  var result = UrlFetchApp.fetch(url, options);
  
  if (result.getResponseCode() == 200) {
    
    var params = JSON.parse(result.getContentText());
    
    Logger.log(params.name);
    Logger.log(params.blog);
    
  }  
}
